# barkeep


## Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md)** <br>Displays a simple animation with a message.  |
| struct | **[barkeep::AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md)** <br>[Animation](api/Classes/classbarkeep_1_1_animation.md) parameters.  |
| class | **[barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)** <br>Base class to handle all asynchronous displays.  |
| struct | **[barkeep::AtomicTraits](api/Classes/structbarkeep_1_1_atomic_traits.md)** <br>Trait class to extract underlying value type from numerics and std::atomics of numerics.  |
| struct | **[barkeep::AtomicTraits< std::atomic< T > >](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md)**  |
| struct | **[barkeep::BarParts](api/Classes/structbarkeep_1_1_bar_parts.md)**  |
| class | **[barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md)** <br>Creates a composite display out of two display that shows them side by side. For instance, you can combine two [Counter](api/Classes/classbarkeep_1_1_counter.md) objects to monitor two variables.  |
| class | **[barkeep::Counter](api/Classes/classbarkeep_1_1_counter.md)** <br>Monitors and displays a single numeric variable.  |
| struct | **[barkeep::CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md)** <br>[Counter](api/Classes/classbarkeep_1_1_counter.md) parameters.  |
| class | **[barkeep::IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md)** <br>A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  |
| struct | **[barkeep::IterableBarConfig](api/Classes/structbarkeep_1_1_iterable_bar_config.md)**  |
| class | **[barkeep::ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)** <br>Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  |
| struct | **[barkeep::ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)**  |
| class | **[barkeep::Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)** <br>Helper class to measure and display speed of progress.  |


</span>

## Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| enum [unsigned](api/Classes/classbarkeep_1_1_counter.md)[short](api/Classes/classbarkeep_1_1_counter.md) | **[AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle)** { Ellipsis, Clock, Moon, Earth, Bar, Square}<br>Kind of animation being displayed for [Animation](api/Classes/classbarkeep_1_1_animation.md).  |
| enum [unsigned](api/Classes/classbarkeep_1_1_counter.md)[short](api/Classes/classbarkeep_1_1_counter.md) | **[ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle)** { Bars, Blocks, Arrow, Pip}<br>Kind of bar being displayed for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md).  |
| using std::vector< std::string > | **[Strings](api/Namespaces/namespacebarkeep.md#using-strings)**  |
| using std::vector< Strings > | **[StringsList](api/Namespaces/namespacebarkeep.md#using-stringslist)**  |
| using std::chrono::duration< [double](api/Classes/classbarkeep_1_1_counter.md), std::ratio< 1 > > | **[Duration](api/Namespaces/namespacebarkeep.md#using-duration)**  |
| template <typename T \> <br>using [typename](api/Classes/classbarkeep_1_1_counter.md)[AtomicTraits](api/Classes/structbarkeep_1_1_atomic_traits.md)< [T](api/Classes/classbarkeep_1_1_counter.md) >::value_type | **[value_t](api/Namespaces/namespacebarkeep.md#using-value_t)**  |
| template <typename T \> <br>using [typename](api/Classes/classbarkeep_1_1_counter.md) std::conditional_t< std::is_integral_v< [T](api/Classes/classbarkeep_1_1_counter.md) >, std::make_signed< [T](api/Classes/classbarkeep_1_1_counter.md) >, std::common_type< [T](api/Classes/classbarkeep_1_1_counter.md) > >::type | **[signed_t](api/Namespaces/namespacebarkeep.md#using-signed_t)**  |


</span>

## Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| Duration | **[as_duration](api/Namespaces/namespacebarkeep.md#function-as_duration)**(std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > interval) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) | **[operator\|](api/Namespaces/namespacebarkeep.md#function-operator\|)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & left, [const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & right)<br>Pipe operator can be used to combine two displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md).  |


</span>

## Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [const](api/Classes/classbarkeep_1_1_counter.md) StringsList | **[animation_stills_](api/Namespaces/namespacebarkeep.md#variable-animation_stills_)** <br>Definitions of various stills for [Animation](api/Classes/classbarkeep_1_1_animation.md). AnimationStyle indexes into this.  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[red](api/Namespaces/namespacebarkeep.md#variable-red)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[green](api/Namespaces/namespacebarkeep.md#variable-green)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[yellow](api/Namespaces/namespacebarkeep.md#variable-yellow)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[blue](api/Namespaces/namespacebarkeep.md#variable-blue)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[magenta](api/Namespaces/namespacebarkeep.md#variable-magenta)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[cyan](api/Namespaces/namespacebarkeep.md#variable-cyan)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::string | **[reset](api/Namespaces/namespacebarkeep.md#variable-reset)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) std::vector< [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) > | **[progress_bar_parts_](api/Namespaces/namespacebarkeep.md#variable-progress_bar_parts_)** <br>Definitions of various partial bars for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). ProgressBarStyle indexes into this.  |

## Types Documentation

### enum AnimationStyle

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Ellipsis | |   |
| Clock | |   |
| Moon | |   |
| Earth | |   |
| Bar | |   |
| Square | |   |



Kind of animation being displayed for [Animation](api/Classes/classbarkeep_1_1_animation.md). 

### enum ProgressBarStyle

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Bars | |   |
| Blocks | |   |
| Arrow | |   |
| Pip | |   |



Kind of bar being displayed for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). 

### using Strings

```cpp
using barkeep::Strings =  std::vector<std::string>;
```


### using StringsList

```cpp
using barkeep::StringsList =  std::vector<Strings>;
```


### using Duration

```cpp
using barkeep::Duration =  std::chrono::duration<double, std::ratio<1>>;
```


### using value_t

```cpp
template <typename T >
using barkeep::value_t =  typename AtomicTraits<T>::value_type;
```


### using signed_t

```cpp
template <typename T >
using barkeep::signed_t =  typename std::conditional_t<std::is_integral_v<T>,
                                             std::make_signed<T>,
                                             std::common_type<T>>::type;
```



## Functions Documentation

### function as_duration

```cpp
Duration as_duration(
    std::variant< Duration, double > interval
)
```


### function operator\|

```cpp
auto operator\|(
    constAsyncDisplay & left,
    constAsyncDisplay & right
)
```

Pipe operator can be used to combine two displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md). 


## Attributes Documentation

### variable animation_stills_

```cpp
static const StringsList animation_stills_ {
    {".  ", ".. ", "..."},
    {"🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓", "🕟", "🕔", "🕠", "🕕", "🕡",
     "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🕛", "🕧"},
    {"🌕", "🌖", "🌗", "🌘", "🌑", "🌒", "🌓", "🌔"},
    {"🌎", "🌍", "🌏"},
    {"-", "/", "|", "\\"},
    {"▖", "▘", "▝", "▗"},
};
```

Definitions of various stills for [Animation](api/Classes/classbarkeep_1_1_animation.md). AnimationStyle indexes into this. 

### variable red

```cpp
static const std::string red = "\033[31m";
```


### variable green

```cpp
static const std::string green = "\033[32m";
```


### variable yellow

```cpp
static const std::string yellow = "\033[33m";
```


### variable blue

```cpp
static const std::string blue = "\033[34m";
```


### variable magenta

```cpp
static const std::string magenta = "\033[35m";
```


### variable cyan

```cpp
static const std::string cyan = "\033[36m";
```


### variable reset

```cpp
static const std::string reset = "\033[0m";
```


### variable progress_bar_parts_

```cpp
static const std::vector< BarParts > progress_bar_parts_ {
    {"|", "|", {"|"}, {" "}},
    {"|", "|", {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"}, {" "}},
    {"|", "|", {">", "="}, {" "}},
    {"",
     "",
     {"╸", "━"},
     {"╺", "━"},
     "\033[38;2;249;38;114m",
     "\033[38;2;114;156;31m",
     "\033[38;5;237m",
     reset,
     cyan,
     reset,
     green,
     reset,
     red,
     reset},
};
```

Definitions of various partial bars for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). ProgressBarStyle indexes into this. 




-------------------------------

Updated on 2024-02-19 at 09:47:42 -0500