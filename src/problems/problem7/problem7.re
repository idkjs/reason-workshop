type shape =
  | Square
  | Circle;

module Shape = {
  module type Shapeable = {let style: ReactDOMRe.Style.t;};
  module type Shape = {let render: string => ReasonReact.reactElement;};
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
    reducer: (action, _state) => ReasonReact.Update(handleClick(action)),
    render: ({ReasonReact.state, reduce}) =>
      <div>
        <div>
          <button onClick={reduce(_ => Circle)}>
            {ReasonReact.stringToElement("show circle")}
          </button>
          <button onClick={reduce(_ => Square)}>
            {ReasonReact.stringToElement("show square")}
          </button>
        </div>
        {switch (state.shape) {
         | Circle =>
           <div> {ReasonReact.stringToElement("change me to a circle")} </div>
         | Square =>
           <div> {ReasonReact.stringToElement("change me to a square")} </div>
         }}
      </div>,
  });
};
