# barkeep


## Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md)**  |
| class | **[barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)** <br>Base class to handle all asynchronous displays.  |
| struct | **[barkeep::AtomicTraits](api/Classes/structbarkeep_1_1_atomic_traits.md)**  |
| struct | **[barkeep::AtomicTraits< std::atomic< T > >](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md)**  |
| class | **[barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md)**  |
| class | **[barkeep::Counter](api/Classes/classbarkeep_1_1_counter.md)**  |
| class | **[barkeep::ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)**  |
| class | **[barkeep::Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)**  |


</span>

## Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| enum [unsigned](api/Classes/classbarkeep_1_1_counter.md)[short](api/Classes/classbarkeep_1_1_counter.md) | **[AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle)** { Ellipsis, Clock, Moon, Earth, Bar, Square}<br>Kind of animation being displayed for [Animation](api/Classes/classbarkeep_1_1_animation.md).  |
| enum [unsigned](api/Classes/classbarkeep_1_1_counter.md)[short](api/Classes/classbarkeep_1_1_counter.md) | **[ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle)** { Bars, Blocks, Arrow}<br>Kind of bar being displayed for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md).  |
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
| [auto](api/Classes/classbarkeep_1_1_counter.md) | **[operator|](api/Namespaces/namespacebarkeep.md#function-operator|)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & left, [const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & right) |


</span>

## Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [const](api/Classes/classbarkeep_1_1_counter.md) StringsList | **[animation_stills_](api/Namespaces/namespacebarkeep.md#variable-animation_stills_)**  |
| [const](api/Classes/classbarkeep_1_1_counter.md) StringsList | **[progress_partials_](api/Namespaces/namespacebarkeep.md#variable-progress_partials_)**  |

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



Kind of bar being displayed for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). 

### using Strings

```cpp
using barkeep::Strings = typedef std::vector<std::string>;
```


### using StringsList

```cpp
using barkeep::StringsList = typedef std::vector<Strings>;
```


### using Duration

```cpp
using barkeep::Duration = typedef std::chrono::duration<double, std::ratio<1> >;
```


### using value_t

```cpp
template <typename T >
using barkeep::value_t = typedef typename AtomicTraits<T>::value_type;
```


### using signed_t

```cpp
template <typename T >
using barkeep::signed_t = typedef typename std::conditional_t<std::is_integral_v<T>, std::make_signed<T>, std::common_type<T> >::type;
```



## Functions Documentation

### function operator|

```cpp
auto operator|(
    constAsyncDisplay & left,
    constAsyncDisplay & right
)
```



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


### variable progress_partials_

```cpp
static const StringsList progress_partials_ {
    {"|"},
    {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"},
    {">", "="},
};
```


Definitions of various partial bars for [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md). ProgressBarStyle indexes into this. 





-------------------------------

Updated on 2023-12-01 at 22:33:53 -0500