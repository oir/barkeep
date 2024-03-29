# barkeep::Animation


Displays a simple animation with a message. 


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle) | **[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)**  |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg ={})<br>Constructor.  |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [Animation](api/Classes/classbarkeep_1_1_animation.md) & other) =default |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) =default |
| | **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual void | **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**() override<br>Render a display: animation, progress bar, etc.  |
| virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) | **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval =[Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.}, std::string message ="", std::string format ="", bool no_tty =false) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual void | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual void | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| bool | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| void | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| void | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual void | **[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| virtual void | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| void | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< bool > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| [Duration](api/Namespaces/namespacebarkeep.md#using-duration) | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
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
    const AnimationConfig & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **cfg** [Animation](api/Classes/classbarkeep_1_1_animation.md) parameters 


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


## Protected Functions Documentation

### function render_

```cpp
inline virtual void render_() override
```

Render a display: animation, progress bar, etc. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


-------------------------------

Updated on 2024-03-28 at 22:58:08 -0400