# barkeep


## Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[ <span class="codey">barkeep::Animation</span> ](api/Classes/classbarkeep_1_1_animation.md)** <br>Displays a simple animation with a message.  |
| struct | **[ <span class="codey">barkeep::AnimationConfig</span> ](api/Classes/structbarkeep_1_1_animation_config.md)** <br>[Animation](api/Classes/classbarkeep_1_1_animation.md) parameters.  |
| class | **[ <span class="codey">barkeep::AsyncDisplay</span> ](api/Classes/classbarkeep_1_1_async_display.md)** <br>Base class to handle all asynchronous displays.  |
| struct | **[ <span class="codey">barkeep::AtomicTraits</span> ](api/Classes/structbarkeep_1_1_atomic_traits.md)** <br>Trait class to extract underlying value type from numerics and std::atomics of numerics.  |
| struct | **[ <span class="codey">barkeep::AtomicTraits< std::atomic< T > ></span> ](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md)**  |
| struct | **[ <span class="codey">barkeep::BarParts</span> ](api/Classes/structbarkeep_1_1_bar_parts.md)**  |
| class | **[ <span class="codey">barkeep::Composite</span> ](api/Classes/classbarkeep_1_1_composite.md)** <br>Creates a composite display out of two display that shows them side by side. For instance, you can combine two [Counter](api/Classes/classbarkeep_1_1_counter.md) objects to monitor two variables.  |
| class | **[ <span class="codey">barkeep::Counter</span> ](api/Classes/classbarkeep_1_1_counter.md)** <br>Monitors and displays a single numeric variable.  |
| struct | **[ <span class="codey">barkeep::CounterConfig</span> ](api/Classes/structbarkeep_1_1_counter_config.md)** <br>[Counter](api/Classes/classbarkeep_1_1_counter.md) parameters.  |
| class | **[ <span class="codey">barkeep::IterableBar</span> ](api/Classes/classbarkeep_1_1_iterable_bar.md)** <br>A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  |
| struct | **[ <span class="codey">barkeep::IterableBarConfig</span> ](api/Classes/structbarkeep_1_1_iterable_bar_config.md)**  |
| class | **[ <span class="codey">barkeep::ProgressBar</span> ](api/Classes/classbarkeep_1_1_progress_bar.md)** <br>Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  |
| struct | **[ <span class="codey">barkeep::ProgressBarConfig</span> ](api/Classes/structbarkeep_1_1_progress_bar_config.md)**  |
| class | **[ <span class="codey">barkeep::Speedometer</span> ](api/Classes/classbarkeep_1_1_speedometer.md)** <br>Helper class to measure and display speed of progress.  |


</span>

## Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> enum unsigned short </span>| **[ <span class="codey"> AnimationStyle</span> ](api/Namespaces/namespacebarkeep.md#enum-animationstyle)** { `Ellipsis`, `Clock`, `Moon`, `Earth`, `Bar`, `Square`}<br>Kind of animation being displayed for [Animation](api/Classes/classbarkeep_1_1_animation.md).  |
| <span class="codey"> enum unsigned short </span>| **[ <span class="codey"> ProgressBarStyle</span> ](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle)** { `Bars`, `Blocks`, `Arrow`, `Pip`}<br>Kind of bar being displayed for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md).  |
| <span class="codey"> using std::vector< std::string > </span>| **[ <span class="codey"> Strings</span> ](api/Namespaces/namespacebarkeep.md#using-strings)**  |
| <span class="codey"> using std::vector< [Strings](api/Namespaces/namespacebarkeep.md#using-strings) > </span>| **[ <span class="codey"> StringsList</span> ](api/Namespaces/namespacebarkeep.md#using-stringslist)**  |
| <span class="codey"> using std::chrono::duration< double, std::ratio< 1 > > </span>| **[ <span class="codey"> Duration</span> ](api/Namespaces/namespacebarkeep.md#using-duration)**  |
| <span class="codey"> template <typename T \> <br>using typename [AtomicTraits](api/Classes/structbarkeep_1_1_atomic_traits.md)< T >::value_type </span>| **[ <span class="codey"> value_t</span> ](api/Namespaces/namespacebarkeep.md#using-value_t)**  |
| <span class="codey"> template <typename T \> <br>using typename std::conditional_t< std::is_integral_v< T >, std::make_signed< T >, std::common_type< T > >::type </span>| **[ <span class="codey"> signed_t</span> ](api/Namespaces/namespacebarkeep.md#using-signed_t)**  |


</span>

## Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span> | <span class="codey">**[as_duration](api/Namespaces/namespacebarkeep.md#function-as_duration)**(std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > interval)</span> |
| <span class="codey"> auto </span> | <span class="codey">**[operator\|](api/Namespaces/namespacebarkeep.md#function-operator\|)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & left, const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & right)</span><br>Pipe operator can be used to combine two displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md).  |


</span>

## Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">const [StringsList](api/Namespaces/namespacebarkeep.md#using-stringslist) </span>| **[<span class="codey">animation_stills_</span>](api/Namespaces/namespacebarkeep.md#variable-animation_stills_)** <br>Definitions of various stills for [Animation](api/Classes/classbarkeep_1_1_animation.md). AnimationStyle indexes into this.  |
| <span class="codey">const std::string </span>| **[<span class="codey">red</span>](api/Namespaces/namespacebarkeep.md#variable-red)**  |
| <span class="codey">const std::string </span>| **[<span class="codey">green</span>](api/Namespaces/namespacebarkeep.md#variable-green)**  |
| <span class="codey">const std::string </span>| **[<span class="codey">yellow</span>](api/Namespaces/namespacebarkeep.md#variable-yellow)**  |
| <span class="codey">const std::string </span>| **[<span class="codey">blue</span>](api/Namespaces/namespacebarkeep.md#variable-blue)**  |
| <span class="codey">const std::string </span>| **[<span class="codey">magenta</span>](api/Namespaces/namespacebarkeep.md#variable-magenta)**  |
| <span class="codey">const std::string </span>| **[<span class="codey">cyan</span>](api/Namespaces/namespacebarkeep.md#variable-cyan)**  |
| <span class="codey">const std::string </span>| **[<span class="codey">reset</span>](api/Namespaces/namespacebarkeep.md#variable-reset)**  |
| <span class="codey">const std::vector< [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) > </span>| **[<span class="codey">progress_bar_parts_</span>](api/Namespaces/namespacebarkeep.md#variable-progress_bar_parts_)** <br>Definitions of various partial bars for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). ProgressBarStyle indexes into this.  |

## Types Documentation

### enum <span class="codey">AnimationStyle</span>

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| <span class="codey">Ellipsis</span> | |   |
| <span class="codey">Clock</span> | |   |
| <span class="codey">Moon</span> | |   |
| <span class="codey">Earth</span> | |   |
| <span class="codey">Bar</span> | |   |
| <span class="codey">Square</span> | |   |



Kind of animation being displayed for [Animation](api/Classes/classbarkeep_1_1_animation.md). 

### enum <span class="codey">ProgressBarStyle</span>

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| <span class="codey">Bars</span> | |   |
| <span class="codey">Blocks</span> | |   |
| <span class="codey">Arrow</span> | |   |
| <span class="codey">Pip</span> | |   |



Kind of bar being displayed for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). 

### using <span class="codey">Strings</span>

```cpp
using barkeep::Strings =  std::vector<std::string>;
```


### using <span class="codey">StringsList</span>

```cpp
using barkeep::StringsList =  std::vector<Strings>;
```


### using <span class="codey">Duration</span>

```cpp
using barkeep::Duration =  std::chrono::duration<double, std::ratio<1>>;
```


### using <span class="codey">value_t</span>

```cpp
template <typename T >
using barkeep::value_t =  typename AtomicTraits<T>::value_type;
```


### using <span class="codey">signed_t</span>

```cpp
template <typename T >
using barkeep::signed_t =  typename std::conditional_t<std::is_integral_v<T>,
                                             std::make_signed<T>,
                                             std::common_type<T>>::type;
```



## Functions Documentation

### function <span class="codey">as_duration</span>

```cpp
Duration as_duration(
    std::variant< Duration, double > interval
)
```


### function <span class="codey">operator\|</span>

```cpp
auto operator\|(
    const AsyncDisplay & left,
    const AsyncDisplay & right
)
```

Pipe operator can be used to combine two displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md). 


## Attributes Documentation

### variable <span class="codey">animation_stills_</span>

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

### variable <span class="codey">red</span>

```cpp
static const std::string red = "\033[31m";
```


### variable <span class="codey">green</span>

```cpp
static const std::string green = "\033[32m";
```


### variable <span class="codey">yellow</span>

```cpp
static const std::string yellow = "\033[33m";
```


### variable <span class="codey">blue</span>

```cpp
static const std::string blue = "\033[34m";
```


### variable <span class="codey">magenta</span>

```cpp
static const std::string magenta = "\033[35m";
```


### variable <span class="codey">cyan</span>

```cpp
static const std::string cyan = "\033[36m";
```


### variable <span class="codey">reset</span>

```cpp
static const std::string reset = "\033[0m";
```


### variable <span class="codey">progress_bar_parts_</span>

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