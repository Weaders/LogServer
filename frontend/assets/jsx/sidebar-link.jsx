import React from 'react'
import { Link } from 'react-router-dom';


class SidebarLink extends React.Component {

    constructor(props) {

        super(props);

        /**
         * @type {Sidebar}
         */
        this.sidebar = props.sidebar;

        this.state = {
            textKey: props.textKey,
            active: props.active,
            url: props.url
        };

        this.linkClick = this.linkClick.bind(this);

    }


    get id() {
        return `link-${this.state.textKey}`;
    }

    /**
     * Click on link!!
     * @param {Event} e
     * @returns {boolean}
     */
    linkClick(e) {
        this.sidebar.updateSelectedLink(this.state.textKey);
    }

    /**
     * Is should update component
     * @param {object} nextProps
     * @param {object} nextState
     * @returns {boolean}
     */
    shouldComponentUpdate(nextProps, nextState) {

        if (nextProps.active !== this.state.active) {

            nextState.active = nextProps.active;
            return true;

        }

        return false;

    }

    render() {

        let className = 'sidebar-link list-group-item list-group-item-action';

        if (this.state.active) {
            className += ' active';
        }

        return <Link onClick={this.linkClick} className={className} id={this.id} to={this.state.url}>{this.state.textKey}</Link>

    }

}

SidebarLink.defaultProps = {
    textKey: 'default-text',
    active: false,
    url: 'default-link'
};

export default SidebarLink;