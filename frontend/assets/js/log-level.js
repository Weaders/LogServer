class LogLevel {

  /**
   * Constructor!
   * @param {null|{ext:string, key: string, name: string}} obj
   */
  constructor(obj = null) {

    /**
     * Extension of file
     * @type {string}
     */
    this.ext = '';

    /**
     * Key of level log
     * @type {string}
     */
    this.key = '';

    /**
     * Name of level log
     * @type {string}
     */
    this.name = '';

    if (obj) {
      this.init(obj);
    }

  }

  /**
   * Init by object
   * @param {{ext:string, key: string, name: string}} obj
   */
  init(obj) {

    if (obj.ext) {
      this.ext = obj.ext;
    }

    if (obj.name) {
      this.name = obj.name;
    }

    if (obj.key) {
      this.key = obj.key;
    }

  }

}

export default LogLevel;