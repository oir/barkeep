# barkeep::Animation




Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using AnimationStyle | **[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)**  |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(std::ostream & out =std::cout) |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [Animation](api/Classes/classbarkeep_1_1_animation.md) & other) =default |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) =default |
| | **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override |
| auto & | **[style](api/Classes/classbarkeep_1_1_animation.md#function-style)**(Style sty) |
| auto & | **[message](api/Classes/classbarkeep_1_1_animation.md#function-message)**(const std::string & msg) |
| auto & | **[interval](api/Classes/classbarkeep_1_1_animation.md#function-interval)**(Duration pd) |
| auto & | **[interval](api/Classes/classbarkeep_1_1_animation.md#function-interval)**(double pd) |
| auto & | **[no_tty](api/Classes/classbarkeep_1_1_animation.md#function-no_tty)**() |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual size_t | **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual void | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual void | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| void | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**() |
| size_t | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| bool | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**  |


</span>


## Public Types Documentation

### using Style

```cpp
using barkeep::Animation::Style =  AnimationStyle;
```


## Public Functions Documentation

### function Animation

```cpp
inline Animation(
    std::ostream & out =std::cout
)
```


### function Animation

```cpp
Animation(
    const Animation & other
) =default
```


### function Animation

```cpp
Animation(
    Animation && 
) =default
```


### function ~Animation

```cpp
inline ~Animation()
```


### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### function style

```cpp
inline auto & style(
    Style sty
)
```


### function message

```cpp
inline auto & message(
    const std::string & msg
)
```


### function interval

```cpp
inline auto & interval(
    Duration pd
)
```


### function interval

```cpp
inline auto & interval(
    double pd
)
```


### function no_tty

```cpp
inline auto & no_tty()
```


## Protected Functions Documentation

### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```


**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


-------------------------------

Updated on 2023-11-30 at 22:33:04 -0500