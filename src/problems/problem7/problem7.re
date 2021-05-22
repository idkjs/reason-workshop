type shape =
  | Square
  | Circle;

module Shape = {
  module type Shapeable = {let style: ReactDOMRe.Style.t;};
  module type Shape = {let render: string => React.element;};
  module Make = (S: Shapeable) : Shape => {
    include S;
    let render = _ => <div style=S.style />;
  };
}; /*
 use the Shape.Make functor to create two new modules:
   Square
   Circle
 and replace the switch statement in Problem7 to render the correct shapes.
  */

type state = {shape};

[@react.component]
let make = () => {
  let handleClick = shape => {shape: shape};
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    initialState: () => {shape: Circle},
    reducer: (action, _state) => Update(handleClick(action)),
    render: ({state, send}) =>
      <div>
        <div>
          <button onClick={_ => send(Circle)}>
            {React.string("show circle")}
          </button>
          <button onClick={_ => send(Square)}>
            {React.string("show square")}
          </button>
        </div>
        {switch (state.shape) {
         | Circle => <div> {React.string("change me to a circle")} </div>
         | Square => <div> {React.string("change me to a square")} </div>
         }}
      </div>,
  });
};
