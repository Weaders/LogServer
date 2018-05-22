import config from '../config'

const SERVER_API_URL = config.serverUrl + '/v1';

function logsReq(url, opts = {}) {

  if (!opts) {
    opts = {};
  }

  if (url[0] !== '/') {
    url = '/' + url;
  }

  return fetch(SERVER_API_URL + url, opts);

}

export {logsReq};
