// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/cloud/speech/v1beta1/cloud_speech.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_GEN_VERSION != 30001
#error This file was generated by a different version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class RecognitionAudio;
@class RecognitionConfig;
@class SpeechContext;
@class SpeechRecognitionAlternative;
@class SpeechRecognitionResult;
@class Status;
@class StreamingRecognitionConfig;
@class StreamingRecognitionResult;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum RecognitionConfig_AudioEncoding

/**
 * Audio encoding of the data sent in the audio message. All encodings support
 * only 1 channel (mono) audio. Only `FLAC` includes a header that describes
 * the bytes of audio that follow the header. The other encodings are raw
 * audio bytes with no header.
 *
 * For best results, the audio source should be captured and transmitted using
 * a lossless encoding (`FLAC` or `LINEAR16`). Recognition accuracy may be
 * reduced if lossy codecs (such as AMR, AMR_WB and MULAW) are used to capture
 * or transmit the audio, particularly if background noise is present.
 **/
typedef GPB_ENUM(RecognitionConfig_AudioEncoding) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  RecognitionConfig_AudioEncoding_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /** Not specified. Will return result [google.rpc.Code.INVALID_ARGUMENT][google.rpc.Code.INVALID_ARGUMENT]. */
  RecognitionConfig_AudioEncoding_EncodingUnspecified = 0,

  /**
   * Uncompressed 16-bit signed little-endian samples.
   * This is the only encoding that may be used by `AsyncRecognize`.
   **/
  RecognitionConfig_AudioEncoding_Linear16 = 1,

  /**
   * This is the recommended encoding for `SyncRecognize` and
   * `StreamingRecognize` because it uses lossless compression; therefore
   * recognition accuracy is not compromised by a lossy codec.
   *
   * The stream FLAC (Free Lossless Audio Codec) encoding is specified at:
   * http://flac.sourceforge.net/documentation.html.
   * Only 16-bit samples are supported.
   * Not all fields in STREAMINFO are supported.
   **/
  RecognitionConfig_AudioEncoding_Flac = 2,

  /** 8-bit samples that compand 14-bit audio samples using G.711 PCMU/mu-law. */
  RecognitionConfig_AudioEncoding_Mulaw = 3,

  /** Adaptive Multi-Rate Narrowband codec. `sample_rate` must be 8000 Hz. */
  RecognitionConfig_AudioEncoding_Amr = 4,

  /** Adaptive Multi-Rate Wideband codec. `sample_rate` must be 16000 Hz. */
  RecognitionConfig_AudioEncoding_AmrWb = 5,
};

GPBEnumDescriptor *RecognitionConfig_AudioEncoding_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL RecognitionConfig_AudioEncoding_IsValidValue(int32_t value);

#pragma mark - Enum StreamingRecognizeResponse_EndpointerType

/** Indicates the type of endpointer event. */
typedef GPB_ENUM(StreamingRecognizeResponse_EndpointerType) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  StreamingRecognizeResponse_EndpointerType_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /** No endpointer event specified. */
  StreamingRecognizeResponse_EndpointerType_EndpointerEventUnspecified = 0,

  /** Speech has been detected in the audio stream. */
  StreamingRecognizeResponse_EndpointerType_StartOfSpeech = 1,

  /** Speech has ceased to be detected in the audio stream. */
  StreamingRecognizeResponse_EndpointerType_EndOfSpeech = 2,

  /** The end of the audio stream has been reached. and it is being processed. */
  StreamingRecognizeResponse_EndpointerType_EndOfAudio = 3,

  /**
   * This event is only sent when `single_utterance` is `true`. It indicates
   * that the server has detected the end of the user's speech utterance and
   * expects no additional speech. Therefore, the server will not process
   * additional audio. The client should stop sending additional audio data.
   **/
  StreamingRecognizeResponse_EndpointerType_EndOfUtterance = 4,
};

GPBEnumDescriptor *StreamingRecognizeResponse_EndpointerType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL StreamingRecognizeResponse_EndpointerType_IsValidValue(int32_t value);

#pragma mark - CloudSpeechRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface CloudSpeechRoot : GPBRootObject
@end

#pragma mark - SyncRecognizeRequest

typedef GPB_ENUM(SyncRecognizeRequest_FieldNumber) {
  SyncRecognizeRequest_FieldNumber_Config = 1,
  SyncRecognizeRequest_FieldNumber_Audio = 2,
};

/**
 * `SyncRecognizeRequest` is the top-level message sent by the client for
 * the `SyncRecognize` method.
 **/
@interface SyncRecognizeRequest : GPBMessage

/**
 * [Required] The `config` message provides information to the recognizer
 * that specifies how to process the request.
 **/
@property(nonatomic, readwrite, strong, null_resettable) RecognitionConfig *config;
/** Test to see if @c config has been set. */
@property(nonatomic, readwrite) BOOL hasConfig;

/** [Required] The audio data to be recognized. */
@property(nonatomic, readwrite, strong, null_resettable) RecognitionAudio *audio;
/** Test to see if @c audio has been set. */
@property(nonatomic, readwrite) BOOL hasAudio;

@end

#pragma mark - AsyncRecognizeRequest

typedef GPB_ENUM(AsyncRecognizeRequest_FieldNumber) {
  AsyncRecognizeRequest_FieldNumber_Config = 1,
  AsyncRecognizeRequest_FieldNumber_Audio = 2,
};

/**
 * `AsyncRecognizeRequest` is the top-level message sent by the client for
 * the `AsyncRecognize` method.
 **/
@interface AsyncRecognizeRequest : GPBMessage

/**
 * [Required] The `config` message provides information to the recognizer
 * that specifies how to process the request.
 **/
@property(nonatomic, readwrite, strong, null_resettable) RecognitionConfig *config;
/** Test to see if @c config has been set. */
@property(nonatomic, readwrite) BOOL hasConfig;

/** [Required] The audio data to be recognized. */
@property(nonatomic, readwrite, strong, null_resettable) RecognitionAudio *audio;
/** Test to see if @c audio has been set. */
@property(nonatomic, readwrite) BOOL hasAudio;

@end

#pragma mark - StreamingRecognizeRequest

typedef GPB_ENUM(StreamingRecognizeRequest_FieldNumber) {
  StreamingRecognizeRequest_FieldNumber_StreamingConfig = 1,
  StreamingRecognizeRequest_FieldNumber_AudioContent = 2,
};

typedef GPB_ENUM(StreamingRecognizeRequest_StreamingRequest_OneOfCase) {
  StreamingRecognizeRequest_StreamingRequest_OneOfCase_GPBUnsetOneOfCase = 0,
  StreamingRecognizeRequest_StreamingRequest_OneOfCase_StreamingConfig = 1,
  StreamingRecognizeRequest_StreamingRequest_OneOfCase_AudioContent = 2,
};

/**
 * `StreamingRecognizeRequest` is the top-level message sent by the client for
 * the `StreamingRecognize`. Multiple `StreamingRecognizeRequest` messages are
 * sent. The first message must contain a `streaming_config` message and must
 * not contain `audio` data. All subsequent messages must contain `audio` data
 * and must not contain a `streaming_config` message.
 **/
@interface StreamingRecognizeRequest : GPBMessage

@property(nonatomic, readonly) StreamingRecognizeRequest_StreamingRequest_OneOfCase streamingRequestOneOfCase;

/**
 * The `streaming_config` message provides information to the recognizer
 * that specifies how to process the request.
 *
 * The first `StreamingRecognizeRequest` message must contain a
 * `streaming_config`  message.
 **/
@property(nonatomic, readwrite, strong, null_resettable) StreamingRecognitionConfig *streamingConfig;

/**
 * The audio data to be recognized. Sequential chunks of audio data are sent
 * in sequential `StreamingRecognizeRequest` messages. The first
 * `StreamingRecognizeRequest` message must not contain `audio_content` data
 * and all subsequent `StreamingRecognizeRequest` messages must contain
 * `audio_content` data. The audio bytes must be encoded as specified in
 * `RecognitionConfig`. Note: as with all bytes fields, protobuffers use a
 * pure binary representation (not base64).
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSData *audioContent;

@end

/**
 * Clears whatever value was set for the oneof 'streamingRequest'.
 **/
void StreamingRecognizeRequest_ClearStreamingRequestOneOfCase(StreamingRecognizeRequest *message);

#pragma mark - StreamingRecognitionConfig

typedef GPB_ENUM(StreamingRecognitionConfig_FieldNumber) {
  StreamingRecognitionConfig_FieldNumber_Config = 1,
  StreamingRecognitionConfig_FieldNumber_SingleUtterance = 2,
  StreamingRecognitionConfig_FieldNumber_InterimResults = 3,
};

/**
 * The `StreamingRecognitionConfig` message provides information to the
 * recognizer that specifies how to process the request.
 **/
@interface StreamingRecognitionConfig : GPBMessage

/**
 * [Required] The `config` message provides information to the recognizer
 * that specifies how to process the request.
 **/
@property(nonatomic, readwrite, strong, null_resettable) RecognitionConfig *config;
/** Test to see if @c config has been set. */
@property(nonatomic, readwrite) BOOL hasConfig;

/**
 * [Optional] If `false` or omitted, the recognizer will perform continuous
 * recognition (continuing to process audio even if the user pauses speaking)
 * until the client closes the output stream (gRPC API) or when the maximum
 * time limit has been reached. Multiple `SpeechRecognitionResult`s with the
 * `is_final` flag set to `true` may be returned.
 *
 * If `true`, the recognizer will detect a single spoken utterance. When it
 * detects that the user has paused or stopped speaking, it will return an
 * `END_OF_UTTERANCE` event and cease recognition. It will return no more than
 * one `SpeechRecognitionResult` with the `is_final` flag set to `true`.
 **/
@property(nonatomic, readwrite) BOOL singleUtterance;

/**
 * [Optional] If `true`, interim results (tentative hypotheses) may be
 * returned as they become available (these interim results are indicated with
 * the `is_final=false` flag).
 * If `false` or omitted, only `is_final=true` result(s) are returned.
 **/
@property(nonatomic, readwrite) BOOL interimResults;

@end

#pragma mark - RecognitionConfig

typedef GPB_ENUM(RecognitionConfig_FieldNumber) {
  RecognitionConfig_FieldNumber_Encoding = 1,
  RecognitionConfig_FieldNumber_SampleRate = 2,
  RecognitionConfig_FieldNumber_LanguageCode = 3,
  RecognitionConfig_FieldNumber_MaxAlternatives = 4,
  RecognitionConfig_FieldNumber_ProfanityFilter = 5,
  RecognitionConfig_FieldNumber_SpeechContext = 6,
};

/**
 * The `RecognitionConfig` message provides information to the recognizer
 * that specifies how to process the request.
 **/
@interface RecognitionConfig : GPBMessage

/** [Required] Encoding of audio data sent in all `RecognitionAudio` messages. */
@property(nonatomic, readwrite) RecognitionConfig_AudioEncoding encoding;

/**
 * [Required] Sample rate in Hertz of the audio data sent in all
 * `RecognitionAudio` messages. Valid values are: 8000-48000.
 * 16000 is optimal. For best results, set the sampling rate of the audio
 * source to 16000 Hz. If that's not possible, use the native sample rate of
 * the audio source (instead of re-sampling).
 **/
@property(nonatomic, readwrite) int32_t sampleRate;

/**
 * [Optional] The language of the supplied audio as a BCP-47 language tag.
 * Example: "en-GB"  https://www.rfc-editor.org/rfc/bcp/bcp47.txt
 * If omitted, defaults to "en-US". See
 * [Language Support](/speech/docs/best-practices#language_support) for
 * a list of the currently supported language codes.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *languageCode;

/**
 * [Optional] Maximum number of recognition hypotheses to be returned.
 * Specifically, the maximum number of `SpeechRecognitionAlternative` messages
 * within each `SpeechRecognitionResult`.
 * The server may return fewer than `max_alternatives`.
 * Valid values are `0`-`30`. A value of `0` or `1` will return a maximum of
 * `1`. If omitted, defaults to `1`.
 **/
@property(nonatomic, readwrite) int32_t maxAlternatives;

/**
 * [Optional] If set to `true`, the server will attempt to filter out
 * profanities, replacing all but the initial character in each filtered word
 * with asterisks, e.g. "f***". If set to `false` or omitted, profanities
 * won't be filtered out.
 **/
@property(nonatomic, readwrite) BOOL profanityFilter;

/** [Optional] A means to provide context to assist the speech recognition. */
@property(nonatomic, readwrite, strong, null_resettable) SpeechContext *speechContext;
/** Test to see if @c speechContext has been set. */
@property(nonatomic, readwrite) BOOL hasSpeechContext;

@end

/**
 * Fetches the raw value of a @c RecognitionConfig's @c encoding property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t RecognitionConfig_Encoding_RawValue(RecognitionConfig *message);
/**
 * Sets the raw value of an @c RecognitionConfig's @c encoding property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetRecognitionConfig_Encoding_RawValue(RecognitionConfig *message, int32_t value);

#pragma mark - SpeechContext

typedef GPB_ENUM(SpeechContext_FieldNumber) {
  SpeechContext_FieldNumber_PhrasesArray = 1,
};

/**
 * Provides "hints" to the speech recognizer to favor specific words and phrases
 * in the results.
 **/
@interface SpeechContext : GPBMessage

/**
 * [Optional] A list of up to 50 phrases of up to 100 characters each to
 * provide words and phrases "hints" to the speech recognition so that it is
 * more likely to recognize them.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *phrasesArray;
/** The number of items in @c phrasesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger phrasesArray_Count;

@end

#pragma mark - RecognitionAudio

typedef GPB_ENUM(RecognitionAudio_FieldNumber) {
  RecognitionAudio_FieldNumber_Content = 1,
  RecognitionAudio_FieldNumber_Uri = 2,
};

typedef GPB_ENUM(RecognitionAudio_AudioSource_OneOfCase) {
  RecognitionAudio_AudioSource_OneOfCase_GPBUnsetOneOfCase = 0,
  RecognitionAudio_AudioSource_OneOfCase_Content = 1,
  RecognitionAudio_AudioSource_OneOfCase_Uri = 2,
};

/**
 * Contains audio data in the encoding specified in the `RecognitionConfig`.
 * Either `content` or `uri` must be supplied. Supplying both or neither
 * returns [google.rpc.Code.INVALID_ARGUMENT][google.rpc.Code.INVALID_ARGUMENT].
 **/
@interface RecognitionAudio : GPBMessage

@property(nonatomic, readonly) RecognitionAudio_AudioSource_OneOfCase audioSourceOneOfCase;

/**
 * The audio data bytes encoded as specified in
 * `RecognitionConfig`. Note: as with all bytes fields, protobuffers use a
 * pure binary representation, whereas JSON representations use base64.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSData *content;

/**
 * URI that points to a file that contains audio data bytes as specified in
 * `RecognitionConfig`. Currently, only Google Cloud Storage URIs are
 * supported, which must be specified in the following format:
 * `gs://bucket_name/object_name` (other URI formats return
 * [google.rpc.Code.INVALID_ARGUMENT][google.rpc.Code.INVALID_ARGUMENT]). For more information, see
 * [Request URIs](/storage/docs/reference-uris).
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *uri;

@end

/**
 * Clears whatever value was set for the oneof 'audioSource'.
 **/
void RecognitionAudio_ClearAudioSourceOneOfCase(RecognitionAudio *message);

#pragma mark - SyncRecognizeResponse

typedef GPB_ENUM(SyncRecognizeResponse_FieldNumber) {
  SyncRecognizeResponse_FieldNumber_ResultsArray = 2,
};

/**
 * `SyncRecognizeResponse` is the only message returned to the client by
 * `SyncRecognize`. It contains the result as zero or more
 * sequential `RecognizeResponse` messages.
 **/
@interface SyncRecognizeResponse : GPBMessage

/**
 * [Output-only] Sequential list of transcription results corresponding to
 * sequential portions of audio.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionResult*> *resultsArray;
/** The number of items in @c resultsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger resultsArray_Count;

@end

#pragma mark - AsyncRecognizeResponse

typedef GPB_ENUM(AsyncRecognizeResponse_FieldNumber) {
  AsyncRecognizeResponse_FieldNumber_ResultsArray = 2,
};

/**
 * `AsyncRecognizeResponse` is the only message returned to the client by
 * `AsyncRecognize`. It contains the result as zero or more
 * sequential `RecognizeResponse` messages.
 **/
@interface AsyncRecognizeResponse : GPBMessage

/**
 * [Output-only] Sequential list of transcription results corresponding to
 * sequential portions of audio.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionResult*> *resultsArray;
/** The number of items in @c resultsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger resultsArray_Count;

@end

#pragma mark - StreamingRecognizeResponse

typedef GPB_ENUM(StreamingRecognizeResponse_FieldNumber) {
  StreamingRecognizeResponse_FieldNumber_Error = 1,
  StreamingRecognizeResponse_FieldNumber_ResultsArray = 2,
  StreamingRecognizeResponse_FieldNumber_ResultIndex = 3,
  StreamingRecognizeResponse_FieldNumber_EndpointerType = 4,
};

/**
 * `StreamingRecognizeResponse` is the only message returned to the client by
 * `StreamingRecognize`. It contains the result as zero or more
 * sequential `RecognizeResponse` messages.
 **/
@interface StreamingRecognizeResponse : GPBMessage

/**
 * [Output-only] If set, returns a [google.rpc.Status][] message that
 * specifies the error for the operation.
 **/
@property(nonatomic, readwrite, strong, null_resettable) Status *error;
/** Test to see if @c error has been set. */
@property(nonatomic, readwrite) BOOL hasError;

/**
 * [Output-only] This repeated list contains zero or more results that
 * correspond to consecutive portions of the audio currently being processed.
 * It contains zero or one `is_final=true` result (the newly settled portion),
 * followed by zero or more `is_final=false` results.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<StreamingRecognitionResult*> *resultsArray;
/** The number of items in @c resultsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger resultsArray_Count;

/**
 * [Output-only] Indicates the lowest index in the `results` array that has
 * changed. The repeated `SpeechRecognitionResult` results overwrite past
 * results at this index and higher.
 **/
@property(nonatomic, readwrite) int32_t resultIndex;

/** [Output-only] Indicates the type of endpointer event. */
@property(nonatomic, readwrite) StreamingRecognizeResponse_EndpointerType endpointerType;

@end

/**
 * Fetches the raw value of a @c StreamingRecognizeResponse's @c endpointerType property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t StreamingRecognizeResponse_EndpointerType_RawValue(StreamingRecognizeResponse *message);
/**
 * Sets the raw value of an @c StreamingRecognizeResponse's @c endpointerType property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetStreamingRecognizeResponse_EndpointerType_RawValue(StreamingRecognizeResponse *message, int32_t value);

#pragma mark - StreamingRecognitionResult

typedef GPB_ENUM(StreamingRecognitionResult_FieldNumber) {
  StreamingRecognitionResult_FieldNumber_AlternativesArray = 1,
  StreamingRecognitionResult_FieldNumber_IsFinal = 2,
  StreamingRecognitionResult_FieldNumber_Stability = 3,
};

/**
 * A speech recognition result corresponding to a portion of the audio that is
 * currently being processed.
 **/
@interface StreamingRecognitionResult : GPBMessage

/**
 * [Output-only] May contain one or more recognition hypotheses (up to the
 * maximum specified in `max_alternatives`).
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionAlternative*> *alternativesArray;
/** The number of items in @c alternativesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger alternativesArray_Count;

/**
 * [Output-only] If `false`, this `SpeechRecognitionResult` represents an
 * interim result that may change. If `true`, this is the final time the
 * speech service will return this particular `SpeechRecognitionResult`,
 * the recognizer will not return any further hypotheses for this portion of
 * the transcript and corresponding audio.
 **/
@property(nonatomic, readwrite) BOOL isFinal;

/**
 * [Output-only] An estimate of the probability that the recognizer will not
 * change its guess about this interim result. Values range from 0.0
 * (completely unstable) to 1.0 (completely stable). Note that this is not the
 * same as `confidence`, which estimates the probability that a recognition
 * result is correct.
 * This field is only provided for interim results (`is_final=false`).
 * The default of 0.0 is a sentinel value indicating stability was not set.
 **/
@property(nonatomic, readwrite) float stability;

@end

#pragma mark - SpeechRecognitionResult

typedef GPB_ENUM(SpeechRecognitionResult_FieldNumber) {
  SpeechRecognitionResult_FieldNumber_AlternativesArray = 1,
};

/**
 * A speech recognition result corresponding to a portion of the audio.
 **/
@interface SpeechRecognitionResult : GPBMessage

/**
 * [Output-only] May contain one or more recognition hypotheses (up to the
 * maximum specified in `max_alternatives`).
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionAlternative*> *alternativesArray;
/** The number of items in @c alternativesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger alternativesArray_Count;

@end

#pragma mark - SpeechRecognitionAlternative

typedef GPB_ENUM(SpeechRecognitionAlternative_FieldNumber) {
  SpeechRecognitionAlternative_FieldNumber_Transcript = 1,
  SpeechRecognitionAlternative_FieldNumber_Confidence = 2,
};

/**
 * Alternative hypotheses (a.k.a. n-best list).
 **/
@interface SpeechRecognitionAlternative : GPBMessage

/** [Output-only] Transcript text representing the words that the user spoke. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *transcript;

/**
 * [Output-only] The confidence estimate between 0.0 and 1.0. A higher number
 * means the system is more confident that the recognition is correct.
 * This field is typically provided only for the top hypothesis, and only for
 * `is_final=true` results.
 * The default of 0.0 is a sentinel value indicating confidence was not set.
 **/
@property(nonatomic, readwrite) float confidence;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
