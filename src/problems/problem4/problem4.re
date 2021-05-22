let normalStyle = ReactDOMRe.Style.make();

let clickedStyle = ReactDOMRe.Style.make();

let hoveredStyle = ReactDOMRe.Style.make();

let boxStyle =
  ReactDOMRe.Style.make(
    ~width="50px",
    ~height="50px",
    ~border="1px black solid",
    (),
  );

type state = {
  hovered: bool,
  clicked: bool,
};

let handleClick = state =>
  /* change this function to return the existing state
     with the clicked prop set to true. you can use the object spread operator
     { ...state, foo: bar } */
  state;

let handleHover = (_flag, state) =>
  /* change this function to return the existing state
     with the hovered prop set to true. you can use the object spread operator
     { ...state, foo: bar } */
  state;

let switchStyle = state =>
  switch (state.clicked, state.hovered) {
  /* add the cases so that:
     clicked: true hovered: false => clicked style
     clicked: true hovered: true => hovered style
     clicked: false hovered: true => hovered style
     clicked: false hovered: false => empty style */
  | _ => normalStyle
  };

type action =
  | Click
  | Hover(bool);

[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    initialState: () => {hovered: false, clicked: false},
    reducer: (action, state) =>
      switch (action) {
      | Click => Update(handleClick(state))
      | Hover(flag) => Update(handleHover(flag, state))
      },
    render: ({state, send}) => {
      let style = switchStyle(state);
      <div
        style={ReactDOMRe.Style.combine(boxStyle, style)}
        onClick={_ => send(Click)}
        onMouseEnter={_ => send(Hover(true))}
        onMouseLeave={_ => send(Hover(false))}
      />;
    },
  });
