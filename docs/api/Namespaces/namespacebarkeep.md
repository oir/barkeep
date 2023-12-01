# barkeep


## Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md)**  |
| class | **[barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**  |
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
| enum unsigned short | **[AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle)** { Ellipsis, Clock, Moon, Earth, Bar, Square} |
| enum unsigned short | **[ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle)** { Bars, Blocks, Arrow} |
| enum class unsigned short | **[Speed](api/Namespaces/namespacebarkeep.md#enum-speed)** { None, Last, Overall, Both} |
| using std::vector< std::string > | **[Strings](api/Namespaces/namespacebarkeep.md#using-strings)**  |
| using std::vector< Strings > | **[StringsList](api/Namespaces/namespacebarkeep.md#using-stringslist)**  |
| using std::chrono::duration< double, std::ratio< 1 > > | **[Duration](api/Namespaces/namespacebarkeep.md#using-duration)**  |
| template <typename T \> <br>using typename [AtomicTraits](api/Classes/structbarkeep_1_1_atomic_traits.md)< T >::value_type | **[value_t](api/Namespaces/namespacebarkeep.md#using-value_t)**  |
| template <typename T \> <br>using typename std::conditional_t< std::is_integral_v< T >, std::make_signed< T >, std::common_type< T > >::type | **[signed_t](api/Namespaces/namespacebarkeep.md#using-signed_t)**  |


</span>

## Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| auto | **[operator|](api/Namespaces/namespacebarkeep.md#function-operator|)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & left, const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & right) |


</span>

## Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| const StringsList | **[animation_stills_](api/Namespaces/namespacebarkeep.md#variable-animation_stills_)**  |
| const StringsList | **[progress_partials_](api/Namespaces/namespacebarkeep.md#variable-progress_partials_)**  |

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




### enum ProgressBarStyle

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Bars | |   |
| Blocks | |   |
| Arrow | |   |




### enum Speed

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| None | |   |
| Last | |   |
| Overall | |   |
| Both | |   |




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
    const AsyncDisplay & left,
    const AsyncDisplay & right
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


### variable progress_partials_

```cpp
static const StringsList progress_partials_ {
    {"|"},
    {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"},
    {">", "="},
};
```





-------------------------------

Updated on 2023-11-30 at 22:43:39 -0500