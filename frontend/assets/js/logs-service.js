import { logsReq } from "./common";

class LogsService {

    constructor() {

        this._getLogsFilesInit();
        this._cbs = new Map();

        this.logFiles = [];

    }

    subscribe(key, cb) {
        this._cbs.set(key, cb);
    }

    unsubscrive(key) {
        this._cbs.delete(key);
    }

    _notifyLogsFiles(files) {


    }

    _getLogsFilesInit() {

        setTimeout(() => {

            logsReq('logs')
                .then((files) => {
                    console.log(files);
                })

        }, 2000)

    }

}

export default LogsService;