[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    render: _self => <div /* replace this with a call to <Square /> */ />,
  });
