import React from 'react';
import SidebarLink from './sidebar-link'


class Sidebar extends React.Component {

    /**
     * Default links
     * @returns {string[]}
     */
    static get defaultLinks() {

        return [
            { key: 'common', url: '/' },
            { key: 'logs', url: '/logs' }
        ];

    }

    constructor(props) {

        super(props);

        let activeLink = null;

        for (let link of props.links) {

            if (link.url === window.location.pathname) {

                activeLink = link.key;
                break;

            }

        }

        if (!activeLink) {
            activeLink = props.links.length ? props.links[0].key : null;
        }

        this.state = {
            colWidth: props.colWidth,
            links: props.links,
            activeLink: activeLink
        };

    }

    /**
     * Update selected link key
     * @param {string} key
     */
    updateSelectedLink(key) {

        this.setState((state) => {

            state.activeLink = key;
            return state;

        });

    }

    render() {

        let eles = this.state.links.map((link) => {

            let active = false;

            if (link.key === this.state.activeLink) {
                active = true;
            }

            return <SidebarLink sidebar={this} url={link.url} active={active} key={link.key} textKey={link.key} />

        });

        // TODO: remove colWidth
        let className = `sidebar col-${this.state.colWidth}`;

        return <div className={className}>
            <div className="sidebar-links list-group">
                {eles}
            </div>
        </div>

    }

}

Sidebar.defaultProps = {
    colWidth: 2,
    links: Sidebar.defaultLinks,
    activeLink: null
};

export default Sidebar;