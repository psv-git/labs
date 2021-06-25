import React from "react";



class ScrollAnchor extends React.Component {

    render() {
        return (
            <div
                ref={this.props.this_ref}
            />
        );
    };

};



export default React.forwardRef((props, ref) =>
    <ScrollAnchor
        {...props}
        this_ref={ref}
    />
);
