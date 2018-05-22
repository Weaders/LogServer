import React from "react";
import {serviceFactory, LOGS_SERVICE_KEY} from './../js/service-factory';
import LogFilesNotify from './../js/log-files-notify';

class MainContentLogs extends React.Component {

  constructor(props) {

    super(props);

    this._mount = false;

    /**
     * Logs service
     * @type {LogsService}
     * @private
     */
    this._logService = serviceFactory.getService(LOGS_SERVICE_KEY);

    /**
     * @type {{files: LogFile[]}}
     */
    this.state = {
      files: []
    };

  }

  /**
   * Component has been mounted
   */
  componentDidMount() {
    this._logService.subscribe('main-content-logs', this.receiveNotify.bind(this), {getCurrent: true});
  }

  componentWillUnmount() {
    this._logService.unsubscribe('main-content-logs');
  }

  /**
   * Get notify of files
   * @param {LogFilesNotify} cmd
   */
  receiveNotify(cmd) {

    if (cmd instanceof LogFilesNotify) {

      this.setState((state) => {

        state.files = cmd.files;
        return state;

      });

    }

  }

  render() {

    let filesOutput = this.state.files.map((f) => {
      return <li key={f.fileName}>{f.fileName}</li>
    });


    return <ul>{filesOutput}</ul>
  }

}

export default MainContentLogs;