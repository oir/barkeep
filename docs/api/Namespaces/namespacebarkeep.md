# barkeep


## Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| struct | **[ <span class="codey">barkeep::AnimationConfig</span> ](api/Classes/structbarkeep_1_1_animation_config.md)** <br>Animation parameters.  |
| class | **[ <span class="codey">barkeep::AnimationDisplay</span> ](api/Classes/classbarkeep_1_1_animation_display.md)** <br>Displays a simple animation with a message.  |
| class | **[ <span class="codey">barkeep::AsyncDisplayer</span> ](api/Classes/classbarkeep_1_1_async_displayer.md)** <br>Class to handle running display loop within a worker thread.  |
| struct | **[ <span class="codey">barkeep::AtomicTraits</span> ](api/Classes/structbarkeep_1_1_atomic_traits.md)** <br>Trait class to extract underlying value type from numerics and std::atomics of numerics.  |
| struct | **[ <span class="codey">barkeep::AtomicTraits< std::atomic< T > ></span> ](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md)**  |
| struct | **[ <span class="codey">barkeep::BarParts</span> ](api/Classes/structbarkeep_1_1_bar_parts.md)**  |
| class | **[ <span class="codey">barkeep::BaseDisplay</span> ](api/Classes/classbarkeep_1_1_base_display.md)** <br>Base class to handle all asynchronous displays.  |
| class | **[ <span class="codey">barkeep::CompositeDisplay</span> ](api/Classes/classbarkeep_1_1_composite_display.md)** <br>Creates a composite display out of multiple child displays to show them together. For instance, you can combine two Counter objects, or a Counter and a ProgressBar to concurrently monitor two variables.  |
| struct | **[ <span class="codey">barkeep::CounterConfig</span> ](api/Classes/structbarkeep_1_1_counter_config.md)** <br>Counter parameters.  |
| class | **[ <span class="codey">barkeep::CounterDisplay</span> ](api/Classes/classbarkeep_1_1_counter_display.md)** <br>Monitors and displays a single numeric variable.  |
| class | **[ <span class="codey">barkeep::IterableBar</span> ](api/Classes/classbarkeep_1_1_iterable_bar.md)** <br>A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  |
| struct | **[ <span class="codey">barkeep::IterableBarConfig</span> ](api/Classes/structbarkeep_1_1_iterable_bar_config.md)** <br>[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md) parameters.  |
| struct | **[ <span class="codey">barkeep::ProgressBarConfig</span> ](api/Classes/structbarkeep_1_1_progress_bar_config.md)** <br>Progress bar parameters.  |
| class | **[ <span class="codey">barkeep::ProgressBarDisplay</span> ](api/Classes/classbarkeep_1_1_progress_bar_display.md)** <br>Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  |
| class | **[ <span class="codey">barkeep::Speedometer</span> ](api/Classes/classbarkeep_1_1_speedometer.md)** <br>Helper class to measure and display speed of progress.  |
| class | **[ <span class="codey">barkeep::StatusDisplay</span> ](api/Classes/classbarkeep_1_1_status_display.md)** <br>Status is an Animation where it is possible to update the message while the animation is running.  |


</span>

## Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> enum unsigned short </span>| **[ <span class="codey"> AnimationStyle</span> ](api/Namespaces/namespacebarkeep.md#enum-animationstyle)** { `Ellipsis`, `Clock`, `Moon`, `Earth`, `Bar`, `UnicodeBar`, `Bounce`}<br>Kind of animation being displayed for Animation.  |
| <span class="codey"> enum unsigned short </span>| **[ <span class="codey"> ProgressBarStyle</span> ](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle)** { `Bars`, `Blocks`, `Rich`, `Line`}<br>Kind of bar being displayed for ProgressBar.  |
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
| <span class="codey"> auto </span> | <span class="codey">**[Animation](api/Namespaces/namespacebarkeep.md#function-animation)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg ={})</span><br>Convenience factory function to create a shared_ptr to [AnimationDisplay](api/Classes/classbarkeep_1_1_animation_display.md). Prefer this to constructing [AnimationDisplay](api/Classes/classbarkeep_1_1_animation_display.md) directly.  |
| <span class="codey"> auto </span> | <span class="codey">**[Status](api/Namespaces/namespacebarkeep.md#function-status)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg ={})</span><br>Convenience factory function to create a shared_ptr to [StatusDisplay](api/Classes/classbarkeep_1_1_status_display.md). Prefer this to constructing [StatusDisplay](api/Classes/classbarkeep_1_1_status_display.md) directly.  |
| <span class="codey"> template <typename Progress \> <br>auto </span> | <span class="codey">**[Counter](api/Namespaces/namespacebarkeep.md#function-counter)**(Progress * progress, const [CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md) & cfg ={})</span><br>Convenience factory function to create a shared_ptr to [CounterDisplay](api/Classes/classbarkeep_1_1_counter_display.md). Prefer this to constructing [CounterDisplay](api/Classes/classbarkeep_1_1_counter_display.md) directly.  |
| <span class="codey"> template <typename Progress \> <br>auto </span> | <span class="codey">**[ProgressBar](api/Namespaces/namespacebarkeep.md#function-progressbar)**(Progress * progress, const [ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)< [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< Progress > > & cfg ={})</span><br>Convenience factory function to create a shared_ptr to [ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md). Prefer this to constructing [ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md) directly.  |
| <span class="codey"> auto </span> | <span class="codey">**[Composite](api/Namespaces/namespacebarkeep.md#function-composite)**(const std::vector< std::shared_ptr< [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) > > & displays, std::string delim =" ")</span><br>Convenience factory function to create a shared_ptr to [CompositeDisplay](api/Classes/classbarkeep_1_1_composite_display.md). Prefer this to constructing [CompositeDisplay](api/Classes/classbarkeep_1_1_composite_display.md) directly.  |
| <span class="codey"> auto </span> | <span class="codey">**[operator\|](api/Namespaces/namespacebarkeep.md#function-operator\|)**(std::shared_ptr< [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) > left, std::shared_ptr< [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) > right)</span><br>Pipe operator can be used to combine two displays into a Composite.  |


</span>

## Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">const std::vector< std::pair< [Strings](api/Namespaces/namespacebarkeep.md#using-strings), double > > </span>| **[<span class="codey">animation_stills_</span>](api/Namespaces/namespacebarkeep.md#variable-animation_stills_)** <br>Definitions of various stills for Animation. AnimationStyle indexes into this.  |
| <span class="codey">const auto </span>| **[<span class="codey">red</span>](api/Namespaces/namespacebarkeep.md#variable-red)**  |
| <span class="codey">const auto </span>| **[<span class="codey">green</span>](api/Namespaces/namespacebarkeep.md#variable-green)**  |
| <span class="codey">const auto </span>| **[<span class="codey">yellow</span>](api/Namespaces/namespacebarkeep.md#variable-yellow)**  |
| <span class="codey">const auto </span>| **[<span class="codey">blue</span>](api/Namespaces/namespacebarkeep.md#variable-blue)**  |
| <span class="codey">const auto </span>| **[<span class="codey">magenta</span>](api/Namespaces/namespacebarkeep.md#variable-magenta)**  |
| <span class="codey">const auto </span>| **[<span class="codey">cyan</span>](api/Namespaces/namespacebarkeep.md#variable-cyan)**  |
| <span class="codey">const auto </span>| **[<span class="codey">reset</span>](api/Namespaces/namespacebarkeep.md#variable-reset)**  |
| <span class="codey">const std::vector< [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) > </span>| **[<span class="codey">progress_bar_parts_</span>](api/Namespaces/namespacebarkeep.md#variable-progress_bar_parts_)** <br>Definitions of various partial bars for ProgressBar. ProgressBarStyle indexes into this.  |

## Types Documentation

### enum <span class="codey">AnimationStyle</span>

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| <span class="codey">Ellipsis</span> | |   |
| <span class="codey">Clock</span> | |   |
| <span class="codey">Moon</span> | |   |
| <span class="codey">Earth</span> | |   |
| <span class="codey">Bar</span> | |   |
| <span class="codey">UnicodeBar</span> | |   |
| <span class="codey">Bounce</span> | |   |



Kind of animation being displayed for Animation. 

### enum <span class="codey">ProgressBarStyle</span>

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| <span class="codey">Bars</span> | | Simple ascii pipes.   |
| <span class="codey">Blocks</span> | | Unicode blocks with fine granularity fill.   |
| <span class="codey">Rich</span> | | A style inspired by Rich library, also used by pip.   |
| <span class="codey">Line</span> | | Minimalist unicode line inspired by Rich style.   |



Kind of bar being displayed for ProgressBar. 

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


### function <span class="codey">Animation</span>

```cpp
auto Animation(
    const AnimationConfig & cfg = {}
)
```

Convenience factory function to create a shared_ptr to [AnimationDisplay](api/Classes/classbarkeep_1_1_animation_display.md). Prefer this to constructing [AnimationDisplay](api/Classes/classbarkeep_1_1_animation_display.md) directly. 

### function <span class="codey">Status</span>

```cpp
auto Status(
    const AnimationConfig & cfg = {}
)
```

Convenience factory function to create a shared_ptr to [StatusDisplay](api/Classes/classbarkeep_1_1_status_display.md). Prefer this to constructing [StatusDisplay](api/Classes/classbarkeep_1_1_status_display.md) directly. 

### function <span class="codey">Counter</span>

```cpp
template <typename Progress >
auto Counter(
    Progress * progress,
    const CounterConfig & cfg = {}
)
```

Convenience factory function to create a shared_ptr to [CounterDisplay](api/Classes/classbarkeep_1_1_counter_display.md). Prefer this to constructing [CounterDisplay](api/Classes/classbarkeep_1_1_counter_display.md) directly. 

### function <span class="codey">ProgressBar</span>

```cpp
template <typename Progress >
auto ProgressBar(
    Progress * progress,
    const ProgressBarConfig< value_t< Progress > > & cfg = {}
)
```

Convenience factory function to create a shared_ptr to [ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md). Prefer this to constructing [ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md) directly. 

### function <span class="codey">Composite</span>

```cpp
auto Composite(
    const std::vector< std::shared_ptr< BaseDisplay > > & displays,
    std::string delim = " "
)
```

Convenience factory function to create a shared_ptr to [CompositeDisplay](api/Classes/classbarkeep_1_1_composite_display.md). Prefer this to constructing [CompositeDisplay](api/Classes/classbarkeep_1_1_composite_display.md) directly. 

### function <span class="codey">operator\|</span>

```cpp
auto operator|(
    std::shared_ptr< BaseDisplay > left,
    std::shared_ptr< BaseDisplay > right
)
```

Pipe operator can be used to combine two displays into a Composite. 


## Attributes Documentation

### variable <span class="codey">animation_stills_</span>

```cpp
static const std::vector< std::pair< Strings, double > > animation_stills_ {
    {{".  ", ".. ", "..."}, 0.5},
    {{"🕐", "🕜", "🕑", "🕝", "🕒", "🕞", "🕓", "🕟", "🕔", "🕠", "🕕", "🕡",
      "🕖", "🕢", "🕗", "🕣", "🕘", "🕤", "🕙", "🕥", "🕚", "🕦", "🕛", "🕧"},
     0.5},
    {{"🌕", "🌖", "🌗", "🌘", "🌑", "🌒", "🌓", "🌔"}, 0.5},
    {{"🌎", "🌍", "🌏"}, 0.5},
    {{"-", "/", "|", "\\"}, 0.5},
    {{"╶─╴", " ╱ ", " │ ", " ╲ "}, 0.5},
    {{
         "●                  ", "●                  ", "●                  ",
         "●                  ", " ●                 ", "  ●                ",
         "   ●               ", "     ●             ", "       ●           ",
         "         ●         ", "           ●       ", "             ●     ",
         "               ●   ", "                ●  ", "                 ● ",
         "                  ●", "                  ●", "                  ●",
         "                  ●", "                 ● ", "                ●  ",
         "               ●   ", "             ●     ", "           ●       ",
         "         ●         ", "       ●           ", "     ●             ",
         "   ●               ", "  ●                ", " ●                 ",
     },
     0.05}};
```

Definitions of various stills for Animation. AnimationStyle indexes into this. 

### variable <span class="codey">red</span>

```cpp
static const auto red = "\033[31m";
```


### variable <span class="codey">green</span>

```cpp
static const auto green = "\033[32m";
```


### variable <span class="codey">yellow</span>

```cpp
static const auto yellow = "\033[33m";
```


### variable <span class="codey">blue</span>

```cpp
static const auto blue = "\033[34m";
```


### variable <span class="codey">magenta</span>

```cpp
static const auto magenta = "\033[35m";
```


### variable <span class="codey">cyan</span>

```cpp
static const auto cyan = "\033[36m";
```


### variable <span class="codey">reset</span>

```cpp
static const auto reset = "\033[0m";
```


### variable <span class="codey">progress_bar_parts_</span>

```cpp
static const std::vector< BarParts > progress_bar_parts_ {
    {"|", "|", {"|"}, {" "}},
    {"|", "|", {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"}, {" "}},
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
    {"", "", {"╾", "━"}, {"─"}},
};
```

Definitions of various partial bars for ProgressBar. ProgressBarStyle indexes into this. 




-------------------------------