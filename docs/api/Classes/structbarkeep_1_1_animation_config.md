# barkeep::AnimationConfig


Animation parameters. 


`#include <barkeep.h>`

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out](api/Classes/structbarkeep_1_1_animation_config.md#variable-out)** </span><br>output stream  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message](api/Classes/structbarkeep_1_1_animation_config.md#variable-message)** </span><br>message to display before the animation  |
| <span class="codey"> std::variant< [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle), [Strings](api/Namespaces/namespacebarkeep.md#using-strings) > </span> | <span class="codey"> **[style](api/Classes/structbarkeep_1_1_animation_config.md#variable-style)** </span><br>style as AnimationStyle or custom animation as a list of strings  |
| <span class="codey"> std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > </span> | <span class="codey"> **[interval](api/Classes/structbarkeep_1_1_animation_config.md#variable-interval)** </span><br>interval in which the animation is refreshed  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty](api/Classes/structbarkeep_1_1_animation_config.md#variable-no_tty)** </span><br>no-tty mode if true (no `\r`, slower default refresh)  |
| <span class="codey"> bool </span> | <span class="codey"> **[show](api/Classes/structbarkeep_1_1_animation_config.md#variable-show)** </span><br>show the animation immediately after construction  |


</span>

## Public Attributes Documentation

### variable `out`

```cpp
std::ostream * out = &std::cout;
```

output stream 

### variable `message`

```cpp
std::string message = "";
```

message to display before the animation 

### variable `style`

```cpp
std::variant< AnimationStyle, Strings > style = Ellipsis;
```

style as AnimationStyle or custom animation as a list of strings 

### variable `interval`

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the animation is refreshed 

### variable `no_tty`

```cpp
bool no_tty = false;
```

no-tty mode if true (no `\r`, slower default refresh) 

### variable `show`

```cpp
bool show = true;
```

show the animation immediately after construction 

-------------------------------