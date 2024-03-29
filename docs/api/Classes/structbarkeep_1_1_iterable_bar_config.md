# barkeep::IterableBarConfig


 [More...](#detailed-description)


`#include <barkeep.h>`

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-out)** <br>output stream  |
| std::string | **[format](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-format)** <br>format string for the entire progress bar  |
| std::string | **[message](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-message)** <br>message to display with the bar  |
| std::optional< double > | **[speed](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed)** <br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| std::string | **[speed_unit](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed_unit)** <br>unit of speed text next to speed  |
| [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle) | **[style](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-style)** <br>style of progress bar interval in which the progress bar is refreshed  |
| std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > | **[interval](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-interval)**  |
| bool | **[no_tty](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |


</span>

## Detailed Description

```cpp
template <typename ValueType >
struct barkeep::IterableBarConfig;
```

## Public Attributes Documentation

### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

### variable format

```cpp
std::string format = "";
```

format string for the entire progress bar 

### variable message

```cpp
std::string message = "";
```

message to display with the bar 

### variable speed

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

### variable speed_unit

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed 

### variable style

```cpp
ProgressBarStyle style = Blocks;
```

style of progress bar interval in which the progress bar is refreshed 

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

Updated on 2024-03-28 at 22:58:08 -0400