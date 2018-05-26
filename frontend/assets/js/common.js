import config from '../config'

const SERVER_API_URL = config.serverUrl + '/v1';

/**
 * Logs request
 * @param {strings} url
 * @param {{}} opts
 * @return {Promise<Response>}
 */
function logsReq(url, opts = {}) {

  if (!opts) {
    opts = {};
  }

  if (url[0] !== '/') {
    url = '/' + url;
  }

  return fetch(SERVER_API_URL + url, opts);

}

/**
 * Init websocket
 * @param {string} url
 * @return {WebSocket}
 */
function webSocketInit(url) {
  return new WebSocket(SERVER_API_URL + `/${url}`);
}

export {logsReq, webSocketInit};
