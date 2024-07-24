# barkeep::IterableBarConfig


[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md) parameters.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-out)** </span><br>output stream  |
| <span class="codey"> std::string </span> | <span class="codey"> **[format](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-format)** </span><br>format string for the entire progress bar  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-message)** </span><br>message to display with the bar  |
| <span class="codey"> std::optional< double > </span> | <span class="codey"> **[speed](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed)** </span><br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed_unit)** </span><br>unit of speed text next to speed  |
| <span class="codey"> [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle) </span> | <span class="codey"> **[style](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-style)** </span><br>style of progress bar  |
| <span class="codey"> std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > </span> | <span class="codey"> **[interval](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-interval)** </span><br>interval in which the progress bar is refreshed  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-no_tty)** </span><br>no-tty mode if true (no \r, slower default refresh)  |


</span>

## Detailed Description

```cpp
template <typename ValueType >
struct barkeep::IterableBarConfig;
```

[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md) parameters. 
## Public Attributes Documentation

### variable `out`

```cpp
std::ostream * out = &std::cout;
```

output stream 

### variable `format`

```cpp
std::string format = "";
```

format string for the entire progress bar 

### variable `message`

```cpp
std::string message = "";
```

message to display with the bar 

### variable `speed`

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

### variable `speed_unit`

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed 

### variable `style`

```cpp
ProgressBarStyle style = Blocks;
```

style of progress bar 

### variable `interval`

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the progress bar is refreshed 

### variable `no_tty`

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

-------------------------------