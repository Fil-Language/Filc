const fs = require('fs');
const {execSync} = require('child_process');

const filc = __dirname + '/../../build/filc';

module.exports = {
    name: 'Decompile',
    test_f: (test, f_passed, f_failed, f_ignore) => {
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
                const first = execSync(filc + ' ' + path + ' -d').toString();
                // Push first to temp file
                fs.writeFileSync(__dirname + '/temp.fil', first);
                // Decompile file second
                const second = execSync(filc + ' ' + __dirname + '/temp.fil -d').toString();


                // Result
                if (first === second) {
                    f_passed(file);
                    passed++;
                } else {
                    f_failed(file);
                }
            } catch (e) {
                f_failed(file);
            }
            total++;
        }

        // Remove temp file
        fs.rmSync(__dirname + '/temp.fil');

        return passed === total;
    }
}