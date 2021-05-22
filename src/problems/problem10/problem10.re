let style = ReactDOMRe.Style.make();
/* place the appropriate styles here */

[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    render: _self => <div style />,
  });
