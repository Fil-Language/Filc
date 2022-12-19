const fs = require('fs');
const {execSync} = require('child_process');

const getExpected = (file) => {
    // Remove the .fil extension and add .ast
    const path = file.replace(/\.fil$/, '.ast');

    return fs.readFileSync(path, 'utf8');
}

module.exports = {
    name: 'AST',
    test_f: (filc, f_passed, f_failed, f_ignore, f_log) => {
        // Get all files in folder (except test.js)
        const files = fs.readdirSync(__dirname).filter(f => f !== 'test.js');

        if (files.length === 0) {
            return undefined;
        }

        let total = 0;
        let passed = 0;
        for (const file of files) {
            try {
                const path = __dirname + '/' + file;

                // Compile file with -a flag
                const ast = execSync(filc + ' ' + path + ' -a 2> err.txt').toString();
                const expected = getExpected(path);

                const errs = fs.readFileSync('err.txt').toString();
                if (errs !== '') {
                    f_failed(file);
                    f_log(`- ${file} failed\n`);
                    f_log(`Error: ${errs}\n`);
                } else
                    // Result
                if (ast === expected) {
                    f_passed(file);
                    f_log(`- ${file} passed\n`);
                    passed++;
                } else {
                    f_failed(file);
                    f_log(`- ${file} failed\n`);
                    f_log(`Expected:\n=>${expected}<=\n`);
                    f_log(`Actual:\n=>${ast}<=\n`);
                }
            } catch (e) {
                f_failed(file);
                f_log(`- ${file} failed\n`);
                f_log(`Error: ${fs.readFileSync('err.txt').toString()}\n`);
            }
            total++;
        }

        // Remove temp file
        fs.rmSync('err.txt');

        return passed === total;
    }
}