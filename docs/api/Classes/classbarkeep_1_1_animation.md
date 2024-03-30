# barkeep::Animation


Displays a simple animation with a message. 


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle) </span>| <span class="codey">**[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)** </span> |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg ={})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [Animation](api/Classes/classbarkeep_1_1_animation.md) & other) =default</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) =default</span> |
| <span class="codey"> </span>|  <span class="codey">  **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**() override</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override</span> |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval =[Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.}, std::string message ="", std::string format ="", bool no_tty =false)</span> |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other)</span> |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other)</span> |
| <span class="codey">virtual </span>| <span class="codey">**[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**()</span> |
| <span class="codey">virtual void </span>| <span class="codey">**[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()</span><br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| <span class="codey">virtual void </span>| <span class="codey">**[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey">bool </span>| <span class="codey">**[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const</span> |


</span>

**Protected Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">void </span>| <span class="codey">**[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()</span><br>Display everything (message, maybe with animation, progress bar, etc).  |
| <span class="codey">void </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey">virtual void </span>| <span class="codey">**[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| <span class="codey">virtual void </span>| <span class="codey">**[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()</span><br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| <span class="codey">void </span>| <span class="codey">**[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const</span> |


</span>

**Protected Attributes inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">std::ostream * </span>| <span class="codey">**[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)** </span> |
| <span class="codey">std::unique_ptr< std::thread > </span>| <span class="codey">**[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)** </span> |
| <span class="codey">std::condition_variable </span>| <span class="codey">**[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)** </span> |
| <span class="codey">std::mutex </span>| <span class="codey">**[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)** </span> |
| <span class="codey">std::atomic< bool > </span>| <span class="codey">**[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)** </span> |
| <span class="codey">[Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey">**[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)** </span> |
| <span class="codey">std::string </span>| <span class="codey">**[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)** </span> |
| <span class="codey">std::string </span>| <span class="codey">**[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)** </span> |
| <span class="codey">bool </span>| <span class="codey">**[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)** </span> |


</span>

**Friends inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | <span class="codey">**[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**</span>  |


</span>


## Public Types Documentation

### using `Style`

```cpp
using barkeep::Animation::Style =  AnimationStyle;
```


## Public Functions Documentation

### function `Animation`

```cpp
inline Animation(
    const AnimationConfig & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **cfg** [Animation](api/Classes/classbarkeep_1_1_animation.md) parameters 


### function `Animation`

```cpp
Animation(
    const Animation & other
) =default
```


### function `Animation`

```cpp
Animation(
    Animation && 
) =default
```


### function `~Animation`

```cpp
inline ~Animation()
```


### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


## Protected Functions Documentation

### function `render_`

```cpp
inline virtual void render_() override
```

Render a display: animation, progress bar, etc. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::default_interval_`](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


-------------------------------

Updated on 2024-03-29 at 22:06:17 -0400