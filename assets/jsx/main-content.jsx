import React from 'react';

class MainContent extends React.Component {

    constructor(props) {

        super(props);
        this.state = {
            colWidth: props.colWidth
        };

    }

    render() {

        let className = `main-content col-${this.state.colWidth}`;
        return <div className={className}>test</div>

    }

}

MainContent.defaultProps = {
    colWidth: 10
};

export default MainContent;