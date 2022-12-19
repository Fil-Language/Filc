require('colors');
const fs = require('fs');

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
let tests = [
    'decompile/test.js',
    'ast/test.js',
]; // Array of tests

const f_passed = (name) => {
    n_passed++;
    n_total++;
    console.log('  ' + '✓'.green + ' ' + name);
}
const f_failed = (name) => {
    n_total++;
    console.log('  ' + '✗'.red + ' ' + name);
}
const f_ignore = (name) => {
    n_passed++;
    n_total++;
    console.log('  ' + '⚠'.yellow + ' ' + name);
}

const f_log = (msg) => {
    fs.writeFileSync('log.txt', msg, {flag: 'a'});
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

let test_time = 0;
if (tests.length > 0) {
    const start = Date.now();

    fs.rmSync('log.txt', {force: true});
    console.log(`Running ${tests.length} tests...`);
    for (const test of tests) {
        console.log('');
        total++;

        try {
            const {test_f, name} = require('./' + test);
            console.log(` ${name} `.bgBlue)
            f_log(`=== ${name} ===\n`);
            const result = test_f(filc, f_passed, f_failed, f_ignore, f_log);
            f_log(`--> ${result} <--\n`)
            f_log(`=== ${name} ===\n`);

            switch (result) {
                case true:
                    passed++;
                    console.log(' ✓ '.bgGreen);
                    break;
                case false:
                    console.log(' ✗ '.bgRed);
                    break;
                case undefined:
                    passed++;
                    console.log(' ⚠ '.bgYellow);
                    break;
            }
        } catch (e) {
            console.log(` ${test} ` + ' Not found '.bgMagenta);
            f_log(`${test} not found\n`);
        }
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