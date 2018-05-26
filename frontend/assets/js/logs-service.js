import {logsReq, webSocketInit} from './common';
import LogFile from './log-file'
import LogFilesNotify from './log-files-notify';
import ServiceListener from './service-listener';

class LogsService extends ServiceListener {

  constructor() {

    super();

    this._getLogsFilesInit();

    /**
     * Web socket for work with logs files.
     * @type {WebSocket|null}
     */
    this.logFilesWs = null;

    /**
     * Array of log files
     * @type {LogFile[]}
     */
    this.logFiles = [];

  }

  /**
   * Subscribe to service
   * @param {string} key
   * @param {Function} cb
   * @param {{}} params
   */
  subscribe(key, cb, params = { getCurrent: false }) {

    super.subscribe(key, cb,);

    if (params.getCurrent) {
      this._notifyLogFiles(key);
    }

  }

  /**
   * Update files, and check is need to notify subscribers
   * @param {{fileName: string, level: object, time: string}[]|LogFile[]} files
   * @returns {boolean} false on no need notify, true on notify
   * @private
   */
  _updateFiles(files) {

    let newFiles = files.filter((f) => {
      return !this._isExistsFile(f);
    });

    if (newFiles.length === 0) {
      return false;
    }

    files = files.map((f) => {
      return new LogFile(f)
    });

    this.logFiles = files;

    return true;

  }

  /**
   * Check is exists Log file
   * @param {{fileName: string}|LogFile} newFile
   * @private
   */
  _isExistsFile(newFile) {

    for (let f of this.logFiles) {

      if (f.fileName === newFile.fileName) {
        return true;
      }

    }

    return false;

  }

  /**
   * Notify subscribers for changed log files
   * @param {string|null} key
   * @private
   */
  _notifyLogFiles(key = null) {

    let notify = new LogFilesNotify(this.logFiles);

    if (!key) {

      for (let cb of this._cbs.values()) {
        cb(notify);
      }

    } else if (this._cbs.has(key)) {
      this._cbs.get(key)(notify);
    }

  }

  /**
   * Get logs files init
   * @private
   */
  _getLogsFilesInit() {

    this.logFilesWs = webSocketInit('logs');
    this.logFilesWs.onmessage = this._getLogsMsg.bind(this);

    this.logFilesWs.send('get-files');

    console.log('test');

    // setInterval(() => {
    //
    //   logsReq('logs')
    //     .then((res) => {
    //       return res.json();
    //     })
    //     .then((files) => {
    //       return this._updateFiles(files);
    //     })
    //     .then((isNotify) => {
    //
    //       if (isNotify) {
    //         this._notifyLogFiles();
    //       }
    //
    //     });
    //
    // }, 20000);

  }

  _getLogsMsg(msg) {

    console.log(msg);

  }



}

export default LogsService;