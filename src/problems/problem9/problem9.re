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
    reducer: (_action, state) => Update(state),
    render: ({state, send}) =>
      <div>
        <Problem9Text color={state.color} onClick={send(_ => ())} />
      </div>,
  });
