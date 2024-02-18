# barkeep::AnimationConfig


[Animation](api/Classes/classbarkeep_1_1_animation.md) parameters. 


`#include <barkeep.h>`

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_animation_config.md#variable-out)** <br>output stream  |
| std::string | **[message](api/Classes/structbarkeep_1_1_animation_config.md#variable-message)** <br>message to display before the animation  |
| AnimationStyle | **[style](api/Classes/structbarkeep_1_1_animation_config.md#variable-style)** <br>style of animation interval in which the animation is refreshed  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_animation_config.md#variable-interval)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_animation_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |


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

message to display before the animation 

### variable style

```cpp
AnimationStyle style = Ellipsis;
```

style of animation interval in which the animation is refreshed 

### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```


### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

-------------------------------

Updated on 2024-02-18 at 11:29:07 -0500