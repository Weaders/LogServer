import _ from 'lodash';
import LogFile from './log-file';

class LogFilesNotify {

  /**
   * Constructor!
   * @param {LogFile[]} files
   */
  constructor(files) {

    /**
     * Array of log files
     * @type {LogFile[]}
     */
    this.files = [];


    if (_.isArray(files)) {
      this.files = files;
    }

  }



}

export default LogFilesNotify;