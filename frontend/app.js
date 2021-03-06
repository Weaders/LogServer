const staticServer = require('node-static');

const fileServer = new staticServer.Server('./assets');

const HOME_FILE = 'index.html';
const HOME_ROUTES = ['/logs'];

const PORT = process.env.PORT || 8080;

require('http').createServer(function (req, res) {

  req.addListener('end', function () {

    if (HOME_ROUTES.indexOf(req.url) !== -1) {
      fileServer.serveFile(HOME_FILE, 200, {}, req, res);
    } else {
      fileServer.serve(req, res);
    }

  }).resume();

}).listen(PORT);

console.log(`Server start at ${PORT}`);