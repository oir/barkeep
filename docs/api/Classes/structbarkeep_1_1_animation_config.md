# barkeep::AnimationConfig


[Animation](api/Classes/classbarkeep_1_1_animation.md) parameters. 


`#include <barkeep.h>`

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_animation_config.md#variable-out)** <br>output stream  |
| std::string | **[message](api/Classes/structbarkeep_1_1_animation_config.md#variable-message)** <br>message to display before the animation style as AnimationStyle or custom animation as a list of strings  |
| std::variant< AnimationStyle, Strings > | **[style](api/Classes/structbarkeep_1_1_animation_config.md#variable-style)**  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_animation_config.md#variable-interval)** <br>interval in which the animation is refreshed  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_animation_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/structbarkeep_1_1_animation_config.md#variable-show)** <br>show the animation immediately after construction  |


</span>

## Public Attributes Documentation

### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

### variable message

```cpp
std::string message = "";
```

message to display before the animation style as AnimationStyle or custom animation as a list of strings 

### variable style

```cpp
std::variant< AnimationStyle, Strings > style = Ellipsis;
```


### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the animation is refreshed 

### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

### variable show

```cpp
bool show = true;
```

show the animation immediately after construction 

-------------------------------

Updated on 2024-03-28 at 21:56:21 -0400