module Extrapolate = {
  type t;
  [@bs.scope ("default", "Extrapolate")]
  [@bs.module "react-native-reanimated"]
  external extend: t = "EXTEND";
  [@bs.scope ("default", "Extrapolate")]
  [@bs.module "react-native-reanimated"]
  external clamp: t = "CLAMP";
  [@bs.scope ("default", "Extrapolate")]
  [@bs.module "react-native-reanimated"]
  external identity: t = "IDENTITY";
};


module Value = {
  type t;

  module Interpolation = {
    type config = {
      inputRange: array(float),
      outputRange: array(float),
    };

    type dynamicConfig = {
      inputRange: array(t),
      outputRange: array(t),
    };

    type dynamicConfigFull = {
      inputRange: array(t),
      outputRange: array(t),
      extrapolateLeft: Extrapolate.t,
      extrapolateRight: Extrapolate.t,
    };

    type configFull = {
      inputRange: array(float),
      outputRange: array(float),
      extrapolateLeft: Extrapolate.t,
      extrapolateRight: Extrapolate.t,
    };
  };

  [@bs.scope "default"] [@bs.module "react-native-reanimated"] [@bs.new]
  external make: float => t = "Value";
  external makeFromValue: t => t = "Value";
  external toAnimated: float => t = "%identity";
  external intToAnimated: int => t = "%identity";
  external boolToAnimated: bool => t = "%identity";

  [@bs.send] external set: (t, t) => unit = "setValue";

  [@bs.scope "default"] [@bs.module "react-native-reanimated"]
  external interpolate: (t, Interpolation.config) => t = "interpolate";

  [@bs.scope "default"] [@bs.module "react-native-reanimated"]
  external interpolateDynamic: (t, Interpolation.dynamicConfig) => t =
    "interpolate";

  [@bs.scope "default"] [@bs.module "react-native-reanimated"]
  external interpolateFull: (t, Interpolation.configFull) => t = "interpolate";

  [@bs.scope "default"] [@bs.module "react-native-reanimated"]
  external interpolateDynamicFull: (t, Interpolation.dynamicConfigFull) => t =
    "interpolate";

  let setInitial = (value: t, initialValue: float): t => {
    Obj.magic(value)##__Custom_InitialValue #= initialValue;
    value;
  };
};
module Clock = {
  type t;
  [@bs.scope "default"] [@bs.module "react-native-reanimated"] [@bs.new]
  external make: unit => t = "Clock";
  external toValue: t => Value.t = "%identity";
};

type springConfig = {
  mass: float,
  stiffness: float,
  damping: float,
  overshootClamping: bool,
  restSpeedThreshold: float,
  restDisplacementThreshold: float,
  toValue: Value.t,
};

type springState = {
  finished: Value.t,
  velocity: Value.t,
  position: Value.t,
  time: Value.t,
};

module SpringUtils = {
  [@bs.scope ("default", "SpringUtils")]
  [@bs.module "react-native-reanimated"]
  external makeDefaultConfig: unit => springConfig = "makeDefaultConfig";
};

module InterpolatedValue = {
  type t;
  external toFloat: t => float = "%identity";
};

// copied and modified from reason-react-native

module Event = {
  type contentOffset = {y: option(Value.t)};
  type nativeEventMapping = {
    translationX: option(Value.t),
    velocityX: option(Value.t),
    state: option(Value.t),
    contentOffset: option(contentOffset),
    x: option(Value.t),
  };
  type mapping = {nativeEvent: nativeEventMapping};
  let defaultContentOffset = {y: None};
  let defaultEvent = {
    translationX: None,
    velocityX: None,
    state: None,
    contentOffset: None,
    x: None,
  };
};

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external spring: (Clock.t, springState, springConfig) => Value.t = "spring";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external block: array(Value.t) => Value.t = "block";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external cond: (Value.t, Value.t, Value.t) => Value.t = "cond";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external add: (Value.t, Value.t) => Value.t = "add";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external not_: Value.t => Value.t = "not";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external absolute: Value.t => Value.t = "abs";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external greaterThan: (Value.t, Value.t) => Value.t = "greaterThan";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external greaterOrEq: (Value.t, Value.t) => Value.t = "greaterOrEq";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external lessThan: (Value.t, Value.t) => Value.t = "lessThan";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external lessOrEq: (Value.t, Value.t) => Value.t = "lessOrEq";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external sub: (Value.t, Value.t) => Value.t = "sub";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external eq: (Value.t, Value.t) => Value.t = "eq";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external neq: (Value.t, Value.t) => Value.t = "neq";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external color: (Value.t, Value.t, Value.t, Value.t) => Value.t = "color";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external max: (Value.t, Value.t) => Value.t = "max";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external round: Value.t => Value.t = "round";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external divide: (Value.t, Value.t) => Value.t = "divide";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external multiply: (Value.t, Value.t) => Value.t = "multiply";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external onChange: (Value.t, Value.t) => Value.t = "onChange";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external cond1: (Value.t, Value.t) => Value.t = "cond";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external startClock: Clock.t => Value.t = "startClock";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external stopClock: Clock.t => Value.t = "stopClock";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external clockRunning: Clock.t => Value.t = "clockRunning";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external set: (Value.t, Value.t) => Value.t = "set";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external modulo: (Value.t, Value.t) => Value.t = "modulo";

type callFn = array(InterpolatedValue.t) => unit;
[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external call: (array(Value.t), callFn) => Value.t = "call";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external or_: (Value.t, Value.t) => Value.t = "or";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external debug: (string, Value.t) => Value.t = "debug";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external and_: (Value.t, Value.t) => Value.t = "and";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external and3: (Value.t, Value.t, Value.t) => Value.t = "and";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external and4: (Value.t, Value.t, Value.t, Value.t) => Value.t = "and";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external and5: (Value.t, Value.t, Value.t, Value.t, Value.t) => Value.t =
  "and";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external concat: (Value.t, string) => Value.t = "concat";

type arg = unit => Value.t;
[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external useCode1: (arg, array('a)) => unit = "useCode";

[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external createAnimatedComponent: 'a => 'a = "createAnimatedComponent";

type pressEventRet = ReactNative.Event.pressEvent => unit;
[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external pressEvent: array(Event.mapping) => pressEventRet = "event";

type scrollEventRet = ReactNative.Event.scrollEvent => unit;
[@bs.scope "default"] [@bs.module "react-native-reanimated"]
external scrollEvent: array(Event.mapping) => scrollEventRet = "event";

module StyleProp = {
  // methods to allow use of Animated values with Style props
  // these methods should not be used to get the current value

  // for angle, Color.t, and size expressed as percentage,
  // interpolated values are needed where the outputRange is
  // an appropriate array of strings

  external float: Value.t => float = "%identity";
  external int: Value.t => int = "%identity";
  external unsafeAngle: Value.t => ReactNative.Style.angle = "%identity";
  let angle: Value.t => ReactNative.Style.angle =
    angle => concat(angle, "deg")->unsafeAngle;
  external size: Value.t => ReactNative.Style.size = "%identity";
  external margin: Value.t => ReactNative.Style.margin = "%identity";
  external color: Value.t => ReactNative.Color.t = "%identity";
};

module View = {
  include ReactNative.View;
  let make = createAnimatedComponent(ReactNative.View.make);
};
