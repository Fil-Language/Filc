require('colors');

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
    //{file: 'decompile/test.js'},
]; // Array of tests results [{file,name,passed, total}]

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
    n_total++;
    console.log('  ' + '⚠'.yellow + ' ' + name);
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Tests runs

if (tests.length > 0) {
    console.log(`Running ${tests.length} tests...`);
    for (const test of tests) {
        total++;

        try {
            const {test_f, name} = require('./' + test.file);
            console.log(` ${name} `.bgBlue + '\n')
            const result = test_f(test, f_passed, f_failed, f_ignore);

            switch (result) {
                case 'passed':
                    passed++;
                    console.log(' ✓ '.bgGreen);
                    break;
                case 'failed':
                    console.log(' ✗ '.bgRed);
                    break;
                case 'ignore':
                    passed++;
                    console.log(' ⚠ '.bgYellow);
                    break;
            }
        } catch (e) {
            console.log(` ${test.file} ` + ' not found '.bgMagenta);
        }
    }
} else {
    console.log('No tests found'.red);
}

// _.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-._.-.
// Conclusion

console.log('\n=== Conclusion ===\n'.magenta);

console.log('Runs  : ' + ((passed === total) ? ' PASS '.bgGreen : ' FAIL '.bgRed) + `\t${passed}/${total}`);
console.log('Tests : ' + ((n_passed === n_total) ? ' PASS '.bgGreen : ' FAIL '.bgRed) + `\t${n_passed}/${n_total}`);

console.log('\n');

if (total === passed && n_total === n_passed) {
    console.log('                  \n'.bgGreen
        + ' ALL TESTS PASSED \n'.bgGreen
        + '                  \n'.bgGreen);
    process.exit(0);
} else {
    console.log('                   \n'.bgRed
        + ' SOME TESTS FAILED \n'.bgRed
        + '                   \n'.bgRed);
    process.exit(1);
}