module Problem8Inner = {
  [@react.component]
  let make = () => <div> {React.string("Problem 8 Inner Component")} </div>;
};

[@react.component]
let make = () => <div> <Problem8Inner /> </div>;
