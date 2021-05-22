module Problem8Inner = {
  [@react.component]
  let make = () =>
    ReactCompat.useRecordApi({
      ...ReactCompat.component,

      render: _self =>
        <div>
          {ReasonReact.stringToElement("Problem 8 Inner Component")}
        </div>,
    });
};

[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    render: _self => <div> <Problem8Inner /> </div>,
  });
