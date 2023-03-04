require('colors');
const fs = require('fs');
const {execSync} = require('child_process');

console.log('    _______ __    \n' +
    '   / ____(_) /____\n' +
    '  / /_  / / / ___/\n' +
    ' / __/ / / / /__  \n' +
    '/_/   /_/_/\\___/  \n' +
    '                  \n');
console.log('Tests of Fil compiler\n');

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Variables initialization

let total = 0; // Number of tests
let passed = 0; // Number of passed tests
let n_total = 0; // Number of single tests
let n_passed = 0; // Number of passed single tests
let ignored = []; // Array of ignored tests
let failed = []; // Array of failed tests
let tests = [
    {dir: 'decompile', name: 'Decompile', command: '-d'},
]; // Array of tests

const f_passed = (name) => {
    n_passed++;
    n_total++;
    console.log('  ' + '✓'.green + ' ' + name);
}
const f_failed = (name) => {
    n_total++;
    console.log('  ' + '✗'.red + ' ' + name);
    failed.push(name);
}
const f_ignore = (name) => {
    n_passed++;
    n_total++;
    console.log('  ' + '⚠'.yellow + ' ' + name);
    ignored.push(name);
}

const f_log = (msg) => {
    fs.writeFileSync('log.txt', msg, {flag: 'a'});
}

const run_test = (dir, command) => {
    const tests = fs.readdirSync(dir).filter(f => f.endsWith('.fil'));

    if (tests.length === 0) {
        f_log('No tests found\n');
        return undefined;
    }

    let total = 0;
    let passed = 0;
    for (const test of tests) {
        total++;

        const path = `${dir}/${test}`;
        const name = test.replace('.fil', '');
        if (!fs.existsSync(`${dir}/${name}.res`)) {
            f_ignore(test);
            f_log(`- ${test} ignored\n`);
            passed++;
            continue;
        }

        const pass = name.split('_')[0]; // If the test is pass of fail
        if (pass !== 'pass' && pass !== 'fail') {
            f_ignore(test);
            f_log(`- ${test} ignored\n`);
            passed++;
            continue;
        }

        let result = '';
        try {
            result = execSync(`${filc} ${command} ${path} 2> err.txt`).toString();
        } catch (e) {
            // Ignore
        }
        const expected = fs.readFileSync(`${dir}/${name}.res`).toString();
        const errs = fs.readFileSync('err.txt').toString();

        if (pass === 'pass') { // If the test should pass
            if (errs !== '') {
                f_failed(test);
                f_log(`- ${test} failed\n`);
                f_log(`Error: ${errs}\n`);
            } else
                // Result
            if (result === expected) {
                f_passed(test);
                f_log(`- ${test} passed\n`);
                passed++;
            } else {
                f_failed(test);
                f_log(`- ${test} failed\n`);
                f_log(`Result: |${result}|\n`);
                f_log(`Expected: |${expected}|\n`);
            }
        } else { // If the test should fail
            if (errs !== '' && errs === expected) {
                f_passed(test);
                f_log(`- ${test} passed\n`);
                passed++;
            } else {
                f_failed(test);
                f_log(`- ${test} failed\n`);
                f_log(`Error: |${errs}|\n`);
                f_log(`Expected: |${expected}|\n`);
            }
        }

    }

    // Remove temp file
    fs.rmSync('err.txt', {force: true});

    return passed === total;
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Tests runs

const filc = process.platform === 'win32' ? __dirname + '\\..\\build\\Debug\\filc.exe' : __dirname + '/../build/filc';

try {
    fs.accessSync(filc, fs.constants.X_OK);
} catch (e) {
    console.log('Fil compiler not found. Please build it first.'.bold.red);
    process.exit(1);
}

// Set FIL_PATH
if (process.env.FIL_PATH === undefined) {
    process.env.FIL_PATH = __dirname + '/includes';
}

let test_time = 0;
if (tests.length > 0) {
    const start = Date.now();

    fs.rmSync('log.txt', {force: true});
    console.log(`Running ${tests.length} tests...`);
    let p_passed = 0;
    let p_total = 0;
    for (const {dir, name, command} of tests) {
        console.log('');
        total++;

        try {
            console.log(` ${name} `.bgBlue)
            f_log(`=== ${name} ===\n`);
            const result = run_test(dir, command);
            f_log(`--> ${result} <--\n`)
            f_log(`=== ${name} ===\n`);

            switch (result) {
                case true:
                    passed++;
                    console.log(` ✓ ${n_passed - p_passed}/${n_total - p_total} `.bgGreen);
                    break;
                case false:
                    console.log(` ✗ ${n_passed - p_passed}/${n_total - p_total} `.bgRed);
                    break;
                case undefined:
                    passed++;
                    console.log(` ⚠ ${n_passed - p_passed}/${n_total - p_total} `.bgYellow);
                    break;
            }
        } catch (e) {
            console.log(` ${name} ` + ' Not found '.bgMagenta);
            f_log(`${name} not found\n`);
        }

        p_passed = n_passed;
        p_total = n_total;
    }

    test_time = Date.now() - start;
} else {
    console.log('No tests found'.red);
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Conclusion

console.log('\n=== Conclusion ===\n'.magenta);

console.log('Runs  : ' + ((passed === total) ? ' PASS '.bgGreen : ' FAIL '.bgRed) + `\t${passed}/${total}`);
console.log('Tests : ' + ((n_passed === n_total) ? ' PASS '.bgGreen : ' FAIL '.bgRed) + `\t${n_passed}/${n_total}`);
console.log('Time  : ' + `${test_time}ms`.bgBlue);

console.log('\n');

if (ignored.length > 0) {
    console.log('Ignored tests:'.yellow);
    for (const test of ignored) {
        console.log(`- ${test}`);
    }
}

if (failed.length > 0) {
    console.log('Failed tests:'.red);
    for (const test of failed) {
        console.log(`- ${test}`);
    }
}

console.log('\n');

if (total === passed && n_total === n_passed) {
    console.log('                  '.bgGreen + '\n'
        + ' ALL TESTS PASSED '.bgGreen + '\n'
        + '                  '.bgGreen + '\n');
    process.exit(0);
} else {
    console.log('                   '.bgRed + '\n'
        + ' SOME TESTS FAILED '.bgRed + '\n'
        + '                   '.bgRed + '\n');
    process.exit(1);
}