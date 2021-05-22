let boxStyle =
  ReactDOMRe.Style.make(
    ~width="50px",
    ~height="50px",
    ~border="1px black solid",
    (),
  );

[@react.component]
let make = () =>
  ReactCompat.useRecordApi({
    ...ReactCompat.component,

    render: ({handle}) => {
      let handleClick = (_, _) =>
        /* change this function to log "clicked" to the JS console */
        ();
      let handleHover = (_, _) =>
        /* change this function to log "hover began" when the event is a mouseover event  and "hover ended" when the event is a mouseleave event */
        ();
      <div
        style=boxStyle
        onClick={handle(handleClick)}
        onMouseEnter={handle(handleHover)}
        onMouseLeave={handle(handleHover)}
      />;
    },
  });
