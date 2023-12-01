---
title: barkeep::Composite

---

# barkeep::Composite





Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > left, std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > right) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(const [Composite](api/Classes/classbarkeep_1_1_composite.md) & other) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) && other) =default |
| | **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override |
| auto & | **[no_tty](api/Classes/classbarkeep_1_1_composite.md#function-no_tty)**() |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| virtual size_t | **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[left_](api/Classes/classbarkeep_1_1_composite.md#variable-left_)**  |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[right_](api/Classes/classbarkeep_1_1_composite.md#variable-right_)**  |

## Additional inherited members

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual void | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual void | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

|                | Name           |
| -------------- | -------------- |
| void | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**() |
| size_t | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |
| void | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**(const std::string & msg) |
| void | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd) |
| void | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(double pd) |

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

|                | Name           |
| -------------- | -------------- |
| bool | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


## Public Functions Documentation

### function Composite

```cpp
inline Composite(
    std::unique_ptr< AsyncDisplay > left,
    std::unique_ptr< AsyncDisplay > right
)
```


### function Composite

```cpp
inline Composite(
    const Composite & other
)
```


### function Composite

```cpp
Composite(
    Composite && other
) =default
```


### function ~Composite

```cpp
inline ~Composite()
```


### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


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


## Protected Attributes Documentation

### variable left_

```cpp
std::unique_ptr< AsyncDisplay > left_;
```


### variable right_

```cpp
std::unique_ptr< AsyncDisplay > right_;
```


-------------------------------

Updated on 2023-11-30 at 21:28:31 -0500