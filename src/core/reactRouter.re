module Router = {
  [@bs.module "react-router-dom"] [@react.component]
  external make: (~history: 'h=?, ~children: 'a) => React.element =
    "BrowserRouter";
};

module Route = {
  [@bs.module "react-router-dom"] [@react.component]
  external make: (~path: string=?, ~children: 'a) => React.element = "Route";
};

module Switch = {
  [@bs.module "react-router-dom"] [@react.component]
  external make: (~children: 'a) => React.element = "Switch";
};

module Link = {
  [@bs.module "react-router-dom"] [@react.component]
  external make:
    (~className: string=?, ~_to: string, ~children: 'a) => React.element =
    "Link";
};

type locationData = {
  hash: string,
  key: string,
  pathname: string,
  search: string,
};

[@bs.module "react-router-dom"]
external useLocation: unit => locationData = "useLocation";

module NavLink = {
  [@bs.module "react-router-dom"] [@react.component]
  external make:
    (~className: string=?, ~_to: string, ~children: 'a) => React.element =
    "Link";
};

// module BrowserRouter = {
//   [@bs.module "react-router-dom"]
//   external browserRouter: ReasonReact.reactClass = "BrowserRouter";
//   let make = children =>
//     ReasonReact.wrapJsForReason(
//       ~reactClass=browserRouter,
//       ~props=Js.Obj.empty(),
//       children,
//     );
// };

// module ServerRouter = {
//   [@bs.module "react-router"]
//   external staticRouter: ReasonReact.reactClass = "StaticRouter";
//   let make = (~context: Js.Json.t, ~location: Js.Json.t, children) =>
//     ReasonReact.wrapJsForReason(
//       ~reactClass=staticRouter,
//       ~props={"context": context, "location": location},
//       children,
//     );
// };

[@bs.module "react-router"]
external withRouter:
  ('a => React.element, 'a) => React.element;


