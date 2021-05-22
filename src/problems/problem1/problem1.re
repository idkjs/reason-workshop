[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    render: _self =>
      <div
        /* use the ReasonReact.stringToElement function here to make this component render "ReasonML"  */
        /* reason ships with JSX support, similar to React's */
      />,
  });
