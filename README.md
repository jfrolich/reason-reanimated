# Reason Reanimated

Reason bindings for https://github.com/software-mansion/react-native-reanimated.

## How to create an animated component?

```reason
include ReactNative.View;
let make = Reanimated.createAnimatedComponent(ReactNative.View.make)
```

Replace `ReactNative.View` by any other view.
