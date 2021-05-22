[@bs.val] external hot: bool = "module.hot";

[@bs.val]
external accept: (string, unit => unit) => unit = "module.hot.accept";

/****
 * IMPORTANT: needs to be defined as seperate typeotherwise while
 * otherwise reasonml will generate ReactHotLoader.make as
 * function make(param) {
 *   return Root.hot(FormationContainer$Formationembedcore.make, param);
 * }
 *
 * rather then var make = Root.hot(FormationContainer$Formationembedcore.make);
 * when seperate componentFunc type is defined as below
 */
type componentFunc = ({. }) => React.element;

module ReactHotLoader {
  [@bs.obj]
  external makeProps: (~key: string=?, unit) => {. } = "";

  [@bs.module "react-hot-loader/root"]
  external make: ([@bs.uncurry] Js.t({..}) => React.element) => componentFunc = "hot";
};

module Hot {
  let makeProps = ReactHotLoader.makeProps;
  let make = ReactHotLoader.make(Routes.make);
};





// module AppContainer = {
//   let make = children =>
//     ReasonReact.wrapJsForReason(
//       ~reactClass=appContainer,
//       ~props=Js.Obj.empty(),
//       children,
//     );
// };

open ReactRouter;

// let render = c =>
//   ReactDOMRe.renderToElementWithClassName(
//     <AppContainer> <BrowserRouter> {c()} </BrowserRouter> </AppContainer>,
//     "app",
//   );

// render(_ => <Routes />);

[@bs.val] external highlightAll: unit => unit = "Prism.highlightAll";

// if (hot) {
//   /* accept "./routes.js" (fun _ => render (fun _ => <Routes />)); */
//   accept("./routes.js", _ => {
//     render(_ => <Routes />);
//     highlightAll();
//   });
// };
ReactDOMRe.renderToElementWithId(<Hot/>, "app");
highlightAll();
