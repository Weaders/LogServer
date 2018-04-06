import React from 'react';
import Sidebar from './sidebar'
import MainContent from './main-content'
import MainContentLogs from './main-content-logs'
import { BrowserRouter, Route } from 'react-router-dom';

class App extends React.Component {

    constructor(props) {

        super(props);
        this.state = {};

    }

    render() {

        return <BrowserRouter>
                    <div className="body container-fluid">
                        <div className="row">
                            <Sidebar />
                            <Route path="/" exact component={MainContent} />
                            <Route path="/logs" exact component={MainContentLogs} />
                        </div>
                    </div>
                </BrowserRouter>
    }

}

export default App;