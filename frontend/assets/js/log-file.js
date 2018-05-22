import _ from 'lodash';
import LogLevel from './log-level';

class LogFile {

  /**
   * Constructor!
   * @param {null|{fileName: string, time: string|Date, level: object|LogLevel}} obj
   */
  constructor(obj = null) {

    /**
     * File name
     * @type {string}
     */
    this.fileName = '';

    /**
     * Date of file
     * @type {null|Date}
     */
    this.time = null;

    /**
     * Level of log
     * @type {null|LogLevel}
     */
    this.level = null;

    if (obj) {
      this.init(obj);
    }

  }

  /**
   * Init by object
   * @param {{fileName: string, time: string|Date, level: object|LogLevel}} obj
   */
  init(obj) {

    if (obj.fileName) {
      this.fileName = obj.fileName;
    }

    if (obj.time) {

      if (obj.time instanceof Date) {
        this.time = obj.time;
      } else  {
        this.time = this._processDateStr(obj.time);
      }

    }

    if (_.isPlainObject(obj.level) || obj.level instanceof LogLevel) {
      this.level = new LogLevel(obj.level);
    }

  }

  /**
   * Process date str
   * @param {string} dateStr
   * @return {Date|null}
   * @private
   */
  _processDateStr(dateStr) {

    if (!_.isString(dateStr)) {
      return null;
    }

    let dateVal = dateStr.split('-');

    if (dateVal.length !== 3) {
      return null;
    }

    // Indexes: 0 - year, 1 - month, 2 - day

    return new Date(...dateVal);

  }

}

export default LogFile;