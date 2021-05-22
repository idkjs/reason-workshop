// [@bs.module] external reactMarkdown: ReasonReact.reactClass = "react-markdown";

// let make = (~source: string, children) =>
//   ReasonReact.wrapJsForReason(
//     ~reactClass=reactMarkdown,
//     ~props={"source": source},
//     children,
//   );
// https://github.com/elcr/muhblog-reason/blob/master/src/bindings/ReactMarkdown.re
[@bs.module]
[@react.component]
external make: (
    ~source: string,
    // ~escapeHtml: bool,
    // ~renderers: {
    //     .
    //     "virtualHtml": {
    //         .
    //         "tag": string,
    //         "children": React.element
    //     } => React.element,
    //     "code": {
    //         .
    //         "language": string,
    //         "value": string
    //     } => React.element,
    //     "heading": {
    //         .
    //         "level": int,
    //         "children": React.element
    //     } => React.element,
    //     "paragraph": {
    //         .
    //         "children": React.element
    //     } => React.element,
    //     "link": {
    //         .
    //         "href": string,
    //         "children": React.element
    //     } => React.element,
    //     "image": {
    //         .
    //         "src": string
    //     } => React.element
    // }
) => React.element = "react-markdown";
