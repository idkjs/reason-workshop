[@bs.val]
external querySelector: string => option(Dom.element) =
  "window.document.querySelector";

[@bs.val] external highlight: unit => unit = "window.Prism.highlightAll";

let paneStyle =
  ReactDOMRe.Style.make(
    ~maxHeight="100vh",
    ~overflow="auto",
    ~padding="25px",
    (),
  );

[@react.component]
let make = (~description, ~problem, ()) =>{

      <div className="pure-g">
        <div style=paneStyle className="pure-u-1-2">
          <ReactMarkdown source=description />
        </div>
        <div style=paneStyle className="pure-u-1-2"> {problem()} </div>
      </div>};
