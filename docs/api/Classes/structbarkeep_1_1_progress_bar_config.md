# barkeep::ProgressBarConfig


 [More...](#detailed-description)

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-out)** <br>output stream  |
| ValueType | **[total](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-total)** <br>total amount of work for a full bar  |
| std::string | **[format](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-format)** <br>format string for the entire progress bar  |
| std::string | **[message](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-message)** <br>message to display with the bar  |
| std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > | **[speed](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-speed)** <br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| std::string | **[speed_unit](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-speed_unit)** <br>unit of speed text next to speed progress bar style, or custom style as [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) |
| std::variant< ProgressBarStyle, [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) > | **[style](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-style)**  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-interval)** <br>interval in which the progress bar is refreshed  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |


</span>

## Detailed Description

```cpp
template <typename ValueType >
struct barkeep::ProgressBarConfig;
```

## Public Attributes Documentation

### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

### variable total

```cpp
ValueType total = 100;
```

total amount of work for a full bar 

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

unit of speed text next to speed progress bar style, or custom style as [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md)

### variable style

```cpp
std::variant< ProgressBarStyle, BarParts > style = Blocks;
```


### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the progress bar is refreshed 

### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

-------------------------------

Updated on 2024-02-19 at 09:47:42 -0500