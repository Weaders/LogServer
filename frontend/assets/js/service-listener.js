class ServiceListener {

  constructor() {

    /**
     * Map of callbacks
     * @type {Map<string, Function>}
     * @protected
     */
    this._cbs = new Map();

  }

  /**
   * Subscribe to service
   * @param {string} key
   * @param {Function} cb
   * @param {{}} params
   */
  subscribe(key, cb, params = {}) {
    this._cbs.set(key, cb);
  }

  /**
   * Unsubscribe from service
   * @param {string} key
   */
  unsubscribe(key) {
    this._cbs.delete(key);
  }

}

export default ServiceListener;