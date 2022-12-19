const fs = require('fs');
const {execSync} = require('child_process');

module.exports = {
    name: 'Decompile',
    test_f: (filc, test, f_passed, f_failed, f_ignore, f_log) => {
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

                // Decompile file first
                const first = execSync(filc + ' ' + path + ' -d 2> err.txt').toString();
                // Push first to temp file
                fs.writeFileSync(__dirname + '/temp.fil', first);
                // Decompile file second
                const second = execSync(filc + ' ' + __dirname + '/temp.fil -d 2> err.txt').toString();

                const errs = fs.readFileSync('err.txt').toString();
                if (errs !== '') {
                    f_failed(file);
                    f_log(`- ${file} failed\n`);
                    f_log(`Error: ${errs}\n`);
                } else
                    // Result
                if (first === second) {
                    f_passed(file);
                    f_log(`- ${file} passed\n`);
                    passed++;
                } else {
                    f_failed(file);
                    f_log(`- ${file} failed\n`);
                    f_log(`First:\n=>${first}<=\n`);
                    f_log(`Second:\n=>${second}<=\n`);
                }
            } catch (e) {
                f_failed(file);
                f_log(`- ${file} failed\n`);
                f_log(`Error: ${fs.readFileSync('err.txt').toString()}\n`);
            }
            total++;
        }

        // Remove temp file
        fs.rmSync(__dirname + '/temp.fil');
        fs.rmSync('err.txt');

        return passed === total;
    }
}