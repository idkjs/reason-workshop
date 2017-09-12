type shape =
  | Square
  | Circle;

module Shape = {
  module type Shapeable = {let style: ReactDOMRe.Style.t;};
  module type Shape = {let render: string => ReasonReact.reactElement;};
  module Make (S: Shapeable) :Shape => {
    include S;
    let render _ => <div style=S.style />;
  };
};

/*
 use the Shape.Make functor to create two new modules:
   Square
   Circle
 and replace the switch statement in Problem7 to render the correct shapes.
  */
type state = {shape};

let component = ReasonReact.reducerComponent "Problem4";

let make _children => {
  let handleClick shape => {shape: shape};
  {
    ...component,
    initialState: fun () => {shape: Circle},
    reducer: fun action _state => ReasonReact.Update (handleClick action),
    render: fun {ReasonReact.state: state, reduce} =>
      <div>
        <div>
          <button onClick=(reduce (fun _ => Circle))>
            (ReasonReact.stringToElement "show circle")
          </button>
          <button onClick=(reduce (fun _ => Square))>
            (ReasonReact.stringToElement "show square")
          </button>
        </div>
        (
          switch state.shape {
          | Circle => <div> (ReasonReact.stringToElement "change me to a circle") </div>
          | Square => <div> (ReasonReact.stringToElement "change me to a square") </div>
          }
        )
      </div>
  }
};
