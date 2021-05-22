module Problem9Text = {
  [@react.component]
  let make = (~onClick, ~color, ()) =>
    ReactCompat.useRecordApi({
      ...ReactCompat.component,

      render: _self => {
        let style = ReactDOMRe.Style.make();
        /* place the appropriate styles here */
        <div style />;
      },
    });
};

type state = {color: string};

[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    initialState: () => {color: "black"},
    reducer: (_action, state) => ReasonReact.Update(state),
    render: ({state, reduce}) =>
      <div>
        <Problem9Text color={state.color} onClick={reduce(_ => ())} />
      </div>,
  });
