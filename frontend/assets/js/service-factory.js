import LogsService from './logs-service';

const LOGS_SERVICE_KEY = 'logs';

class ServiceFactory {

  constructor() {

    /**
     * Cached services
     * @type {Map<string, ServiceListener>}
     */
    this.serviesCache = new Map();

  }

  /**
   * Get service by key
   * @param key
   * @returns {ServiceListener}
   */
  getService(key) {

    if (key === LOGS_SERVICE_KEY) {
      return this._getLogsService();
    }

  }

  /**
   * Return logs service
   * @returns {ServiceListener}
   * @private
   */
  _getLogsService() {

    if (!this.serviesCache.has(LOGS_SERVICE_KEY)) {
      this.serviesCache.set(LOGS_SERVICE_KEY, new LogsService());
    }

    return this.serviesCache.get(LOGS_SERVICE_KEY);

  }

}

/**
 * @type {ServiceFactory}
 */
let serviceFactory = new ServiceFactory();

export {
  serviceFactory,
  LOGS_SERVICE_KEY
};