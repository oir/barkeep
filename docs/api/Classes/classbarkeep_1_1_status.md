# barkeep::Status


[Status](api/Classes/classbarkeep_1_1_status.md) is an [Animation](api/Classes/classbarkeep_1_1_animation.md) where it is possible to update the message while the animation is running. 


`#include <barkeep.h>`

Inherits from [`barkeep::Animation`](api/Classes/classbarkeep_1_1_animation.md), [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Status](api/Classes/classbarkeep_1_1_status.md#function-status)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg = {})</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Status](api/Classes/classbarkeep_1_1_status.md#function-status)**(const [Status](api/Classes/classbarkeep_1_1_status.md) & other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Status](api/Classes/classbarkeep_1_1_status.md#function-status)**([Status](api/Classes/classbarkeep_1_1_status.md) && other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[~Status](api/Classes/classbarkeep_1_1_status.md#function-~status)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_status.md#function-clone)**() const override</span> |
| <span class="codey"> void </span>|  <span class="codey">  **[message](api/Classes/classbarkeep_1_1_status.md#function-message)**(const std::string & message)</span><br>Update the displayed message. This is thread-safe between the display thread and the calling thread.  |
| <span class="codey"> std::string </span>|  <span class="codey">  **[message](api/Classes/classbarkeep_1_1_status.md#function-message)**()</span><br>Get the current message.  |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_status.md#function-render_)**(bool redraw = false, const std::string & end = " ") override</span><br>Render a display: animation, progress bar, etc.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::mutex </span> | <span class="codey"> **[message_mutex_](api/Classes/classbarkeep_1_1_status.md#variable-message_mutex_)**</span>  |


</span>

## Additional inherited members

**Public Types inherited from [barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle) | **[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)**  |

</span>

**Public Functions inherited from [`barkeep::Animation`](api/Classes/classbarkeep_1_1_animation.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"></span>| <span class="codey">**[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg = {})</span><br>Constructor.  |
| <span class="codey"></span>| <span class="codey">**[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [Animation](api/Classes/classbarkeep_1_1_animation.md) & other) = default</span> |
| <span class="codey"></span>| <span class="codey">**[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) = default</span> |
| <span class="codey"></span>| <span class="codey">**[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**()</span> |


</span>

**Protected Functions inherited from [`barkeep::Animation`](api/Classes/classbarkeep_1_1_animation.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey">**[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override</span> |


</span>

**Protected Attributes inherited from [`barkeep::Animation`](api/Classes/classbarkeep_1_1_animation.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">unsigned short </span>| <span class="codey">**[frame_](api/Classes/classbarkeep_1_1_animation.md#variable-frame_)** </span> |
| <span class="codey">[Strings](api/Namespaces/namespacebarkeep.md#using-strings) </span>| <span class="codey">**[stills_](api/Classes/classbarkeep_1_1_animation.md#variable-stills_)** </span> |
| <span class="codey">[Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey">**[def_interval_](api/Classes/classbarkeep_1_1_animation.md#variable-def_interval_)** </span> |


</span>

</span>

**Public Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out = &std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval = [Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.}, std::string message = "", std::string format = "", bool no_tty = false)</span> |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other)</span> |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other)</span> |
| <span class="codey">virtual </span>| <span class="codey">**[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**()</span> |
| <span class="codey">virtual void </span>| <span class="codey">**[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()</span><br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| <span class="codey">virtual void </span>| <span class="codey">**[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey">bool </span>| <span class="codey">**[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const</span><br>Return true if the display is running.  |


</span>

**Protected Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey">**[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const = 0</span> |
| <span class="codey">void </span>| <span class="codey">**[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**(bool redraw = false)</span><br>Display everything (message, maybe with animation, progress bar, etc).  |
| <span class="codey">long </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey">virtual void </span>| <span class="codey">**[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| <span class="codey">virtual void </span>| <span class="codey">**[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()</span><br>Join the display thread. Protected because python bindings need to override to handle GIL.  |


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
| <span class="codey">long </span>| <span class="codey">**[last_num_newlines_](api/Classes/classbarkeep_1_1_async_display.md#variable-last_num_newlines_)** </span> |
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


## Public Functions Documentation

### function `Status`

```cpp
inline Status(
    const AnimationConfig & cfg = {}
)
```


### function `Status`

```cpp
inline Status(
    const Status & other
)
```


### function `Status`

```cpp
inline Status(
    Status && other
)
```


### function `~Status`

```cpp
inline ~Status()
```


### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::Animation::clone`](api/Classes/classbarkeep_1_1_animation.md#function-clone)


### function `message`

```cpp
inline void message(
    const std::string & message
)
```

Update the displayed message. This is thread-safe between the display thread and the calling thread. 

### function `message`

```cpp
inline std::string message()
```

Get the current message. 

## Protected Functions Documentation

### function `render_`

```cpp
inline virtual long render_(
    bool redraw = false,
    const std::string & end = " "
) override
```

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **redraw** If true, display is assumed to be redrawn. This, e.g. means an [Animation](api/Classes/classbarkeep_1_1_animation.md) should not increment the still frame index. 


**Return**: Number of `\n` characters in the display. 

**Reimplements**: [`barkeep::Animation::render_`](api/Classes/classbarkeep_1_1_animation.md#function-render_)


## Protected Attributes Documentation

### variable `message_mutex_`

```cpp
std::mutex message_mutex_;
```


-------------------------------